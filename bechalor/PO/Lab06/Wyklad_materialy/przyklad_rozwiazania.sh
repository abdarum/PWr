#!/bin/bash


PROG="/home/bk/edu/kpo/zad/z6/bin/robot_scena"

WRKDIR="/tmp/kpo/zad6/${USER}"

mkdir -p "${WRKDIR}/dat"
cd "${WRKDIR}"

${PROG}

rm -r "${WRKDIR}"
