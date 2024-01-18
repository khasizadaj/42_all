#!/bin/bash

if [[ $# -lt 2 ]]; then
	echo "Error: At least 2 positional arguments are required."
	echo "Usage: $0 prj_name version"
fi

PROJECT=$1
VERSION=$2

DEST="$HOME/cave/cursus/$PROJECT-$VERSION"

echo $DEST

if ! test -d $DEST; then
	echo "Folder doesn't exist. Please, clone your project."
	exit 1
fi

cp -r ./include $DEST
cp ./Makefile $DEST
cp -r ./src $DEST

