import logging
import argparse
import os
import sys
import subprocess

from pathlib import Path

from support import *

def create_arg_parser() -> argparse.ArgumentParser:
    """
    Create the command line argument parser

    :returns An argument parser to handle the command line arguments
    :rtype argparse.ArgumentParser
    """

    # Create default argument parser
    parser = BuildArgParser.create_arg_parser()

    # Run formatter on source files
    parser.add_argument(
        "--format",
        action="store_true",
        help="Run formatter on source files")

    return parser


def run_formatter():
    """
    Run the formatter
    """
    clang_filename = BuildPaths.BASE_DIR / ".clang-format"
    source_filetypes = [
        "*.c",
        "*.h",
        "*.cpp",
        "*.hpp"
    ]

    # Create base formatter command (no source filenames)
    format_cmd = ["clang-format",
                  "-i",
                  f"-style=file:{clang_filename}"]

    # Recursively get source files and run formatter on each file
    source_paths = [BuildPaths.SOURCE_DIR, BuildPaths.TEST_DIR]

    for filetype in source_filetypes:
        
        source_files = []
        for source_path in source_paths:
            source_files.extend(source_path.rglob(filetype))

        for file in source_files:
            cmd = format_cmd.copy()
            cmd.append(str(file))

            proc = subprocess.run(
                cmd,
                stdout=sys.stdout,
                stderr=sys.stderr,
                text=True)

            proc.check_returncode()


# Start utility script
exit_code = -1

try:
    # Create logger and argument parser
    logger = BuildLogger.create_logger()
    parser = create_arg_parser()

    # Parse command line arguments
    (args, unknown_args) = parser.parse_known_args()

    # Run formatter
    if args.format:
        try:
            logger.info("Running formatter...")
            run_formatter()

        except:
            logger.error("Run formatter failed")
            raise

    # Done
    logger.info("Utility script finished")
    exit_code = 0
    pass

# Log process stderr
except subprocess.CalledProcessError as ex:
    msgs = [
        "Utility script failed with exception",
        "Process stdout:",
        ex.stdout,
        "Process stderr:",
        ex.stderr]
    msg = '\n'.join(msgs)
    logger.critical(msg)
    logger.exception(ex)

# Exception occurred during script
except BaseException as ex:
    logger.critical("Utility script failed with exception")
    logger.exception(ex)


# Exit with exit_code
finally:
    logger.info(f"Exiting with code {exit_code}")

    sys.stderr.flush()
    sys.stdout.flush()
    sys.exit(exit_code)
