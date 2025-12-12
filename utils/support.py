import logging
import os
import argparse

from pathlib import Path


class BuildArgParser(object):
  """
  Create the default argument parser

  :returns Default argument parser
  :rtype argparse.ArgumentParser
  """
  def create_arg_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
    description = "Project utility script",
    allow_abbrev = False)
    return parser


class BuildLogger(object):
  """
  Create the logger

  :returns Logger to be used during the tests
  :rtype logging.Logger
  """
  def create_logger() -> logging.Logger:
    LOGGING_FORMAT = "[%(levelname)s] - %(message)s"    # Log message format
    LOGGER_NAME = "BUILD_LOGGER"                        # Logger name
    LOG_LEVEL = logging.DEBUG                           # Lowest severity level to log

    # Create logger
    logger = logging.getLogger(LOGGER_NAME)
    logger_formatter = logging.Formatter(LOGGING_FORMAT)

    # Add console handler
    logger_console = logging.StreamHandler()
    logger_console.setFormatter(logger_formatter)
    logger.addHandler(logger_console)

    # Set log level  
    logger.setLevel(LOG_LEVEL)

    return logger


# Set paths
class BuildPaths(object):
  BASE_DIR = Path(os.getcwd())

  SOURCE_DIR = BASE_DIR / "src"
  TEST_DIR = BASE_DIR / "test"
  DOC_CONFIG_DIR = BASE_DIR / "docs"

  BUILD_DIR = BASE_DIR / "build"
  OUTPUT_DIR = BASE_DIR / "output"

  LOG_DIR = OUTPUT_DIR / "logs"
  COVERAGE_DIR = OUTPUT_DIR / "coverage"
  DOCS_DIR = OUTPUT_DIR / "docs"
