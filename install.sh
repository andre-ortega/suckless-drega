#!/bin/bash
set -eou pipefail

TARGET=$HOME/.config/polybar/

mkdir -p $TARGET
cp bar.sh config.ini $TARGET
cd $TARGET
./bar.sh
