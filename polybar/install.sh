#!/bin/bash
set -eou pipefail

SOURCE=$PWD
TARGET=$HOME/.config/polybar/

mkdir -p $TARGET
cd $TARGET
ln -s $SOURCE/config.ini
ln -s $SOURCE/bar.sh
./bar.sh
