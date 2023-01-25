#!/bin/bash

bash << "EOF"
source ./env.sh
export PATH="/home/ff/cs152/sp22/lab1-install/bin:$PATH"
<<<<<<< HEAD
cd /scratch/${USER}/chipyard-cs152-sp24/generators/riscv-sodor/test/custom-bmarks
=======
cd /scratch/${USER}/chipyard-cs152-sp23/generators/riscv-sodor/test/custom-bmarks
>>>>>>> 7f6aaf48 (scripted compilation and PATH stuff into subshell to minimize student headaches)
make
make run
make dump
EOF
