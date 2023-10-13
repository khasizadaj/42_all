#!/usr/bin/env python3

import argparse
import os
import fnmatch
import subprocess

def list_files(directory, allowed_patterns):
    for root, _, files in os.walk(directory):
        for basename in files:
            for pattern in allowed_patterns:
                if fnmatch.fnmatch(basename, pattern):
                    break
            else:
                # No match was found
                yield os.path.join(root, basename)

def run_norminette(directory):
    result = subprocess.run(['norminette', directory], capture_output=True, text=True)
    errors = [line for line in result.stdout.splitlines() if "Error" in line]
    return errors

def main():
    parser = argparse.ArgumentParser(description="Pre-submit script to check folder contents and run norminette.")
    parser.add_argument("--directory", "-d", required=True, help="Path to the folder to be checked.")
    parser.add_argument("--included-files", "-i", required=True, help="Comma-separated list of allowed filenames/extensions.")
    args = parser.parse_args()

    allowed_patterns = [pattern.strip() for pattern in args.included_files.split(",")]

    unexpected_files = list(list_files(args.directory, allowed_patterns))
    if unexpected_files:
        print("ERROR: Found unexpected files:\n")
        for file in unexpected_files:
            print(f" X==X {file}")

    norminette_errors = run_norminette(args.directory)
    if norminette_errors:
        print("\nNorminette Errors:\n")
        for error in norminette_errors:
            if args.directory in error:
                print("")
            print(error)

if __name__ == "__main__":
    main()
