#!/bin/bash

bash << "EOF"
source ./env.sh
export PATH="/home/ff/cs152/sp22/lab1-install/bin:$PATH"
cd /scratch/${USER}/chipyard/generators/riscv-sodor/test/custom-bmarks
make
make run
make dump
EOF
