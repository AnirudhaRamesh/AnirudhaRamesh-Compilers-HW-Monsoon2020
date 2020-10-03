icc -w -O0 -I utilities -I linear-algebra/blas/trmm utilities/polybench.c linear-algebra/blas/trmm/trmm.c -DPOLYBENCH_TIME -o trmm_time_O0;
echo "O0 time: ";
./trmm_time_O0;
icc -w -O1 -I utilities -I linear-algebra/blas/trmm utilities/polybench.c linear-algebra/blas/trmm/trmm.c -DPOLYBENCH_TIME -o trmm_time_O1;
echo "O1 time: ";
./trmm_time_O1;
icc -w -O2 -I utilities -I linear-algebra/blas/trmm utilities/polybench.c linear-algebra/blas/trmm/trmm.c -DPOLYBENCH_TIME -o trmm_time_O2;
echo "O2 time: ";
./trmm_time_O2;
icc -w -O3 -I utilities -I linear-algebra/blas/trmm utilities/polybench.c linear-algebra/blas/trmm/trmm.c -DPOLYBENCH_TIME -o trmm_time_O3;
echo "O3 time: ";
./trmm_time_O3;
icc -w -Os -I utilities -I linear-algebra/blas/trmm utilities/polybench.c linear-algebra/blas/trmm/trmm.c -DPOLYBENCH_TIME -o trmm_time_Os;
echo "Os time: ";
./trmm_time_Os;

icc -w -O0 -I utilities -I linear-algebra/blas/trmm utilities/polybench.c linear-algebra/blas/trmm/trmm.c -o trmm_exec_O0;
echo "O0 size";
ls -l trmm_exec_O0
icc -w -O1 -I utilities -I linear-algebra/blas/trmm utilities/polybench.c linear-algebra/blas/trmm/trmm.c -o trmm_exec_O1;
echo "O1 size";
ls -l trmm_exec_O1
icc -w -O2 -I utilities -I linear-algebra/blas/trmm utilities/polybench.c linear-algebra/blas/trmm/trmm.c -o trmm_exec_O2;
echo "O2 size";
ls -l trmm_exec_O2
icc -w -O3 -I utilities -I linear-algebra/blas/trmm utilities/polybench.c linear-algebra/blas/trmm/trmm.c -o trmm_exec_O3;
echo "O3 size";
ls -l trmm_exec_O3
icc -w -Os -I utilities -I linear-algebra/blas/trmm utilities/polybench.c linear-algebra/blas/trmm/trmm.c -o trmm_exec_Os;
echo "Os size";
ls -l trmm_exec_Os
