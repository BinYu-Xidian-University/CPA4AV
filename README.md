# README

This document shows how to reproduce the experimental results in the paper ***Detecting Atomicity Violations in Interrupt-Driven Programs via Interruption Points Selecting and Delayed ISR-Triggering***.

# CPA4AV

**CPA4AV** is developed to detect the atomicity violations in interrupt-driven programs. By utilizing the strategies of interruption point selection and precise reachability computation, the redundant introduction of the control-flows of interrupt service routines(ISR) and the exploration of infeasible paths in an abstract reachability tree(ART) can be avoid. With this basis,  unserializable interleaving patterns are recognized to detect atomicity violations with data access tables maintained on-the-fly. Delayed ISR-triggering strategy
is employed to reduce the state space. The **CPA4AV** is implemented on top of the open-source model checker [CPAchecker](https://gitlab.com/sosy-lab/software/cpachecker), which supports the BDD-based reachability computation.

# Quick Start for Reproducing the Experimental Results

1. Download the compressed package and unpack it.

   * The general structure of the package is as follow:

   ```bash
   CPA4AV/
   	|-- CPA4AV-Ourtool/
   	|-- Experimental-Results/
   	|-- Racebench-2.1/
   	|-- SV-COMP-2022-Benchmark/
       |-- Racebench-2.1+/
       |-- Real-world-interrupt-driven/
   	|-- README.md
   	|-- REQUIREMENTS.md
   ```

2. Setup the experimental environment.

   * Installing the `jdk11` and `python3.6`

   ```bash
   $ sudo apt install openjdk-11-jdk python3.6
   ```

   * Installing the benchmarking tool: [BenchExec](https://github.com/sosy-lab/benchexec/releases/tag/3.11).

   ```bash
   $ wget https://github.com/sosy-lab/benchexec/releases/download/3.11/benchexec_3.11-2_all.deb
   $ sudo dpkg -i ./benchexec_3.11-2_all.deb
   ```

   **NOTICE**: After this, two tools namely `benchexec` and `table-generator`, will be installed into the system.

   * Configuring the environment:

   ```bash
   $ sudo chmod o+wt /sys/fs/cgroup/cpu,cpuacct/system.slice/benchexec-cgroup.service /sys/fs/cgroup/memory/system.slice/benchexec-cgroup.service
   $ sudo chmod o+wt /sys/fs/cgroup/blkio/system.slice/benchexec-cgroup.service /sys/fs/cgroup/cpuset/system.slice/benchexec-cgroup.service /sys/fs/cgroup/freezer/system.slice/benchexec-cgroup.service
   $ sudo swapoff -a
   ```

3. Confirm that the tool works properly.

   * Use the simple program `test.i` presented in the paper under the folder `CPA4AV-Ourtool` to verify our tool. This program **can** trigger an atomicity violation:

   ```bash
   $ cd ./CPA4AV-Ourtool
   $ ./scripts/cpa.sh -config config/myAnalysis-interrupt-benchmark-racebench-with-interruption-points.properties -heap 4096M -benchmark -timelimit 300s -stats test.i
   ```

   The output would be：

   ```bash
   Running CPAchecker with Java heap of size 4096M.
   Running CPAchecker with default stack size (1024k). Specify a larger value with -stack if needed.
   Language C detected and set for analysis (CPAMain.detectFrontendLanguageIfNecessary, INFO)
   ...
   =========================== Conflicts checked =============================
   The total number of conflicts is 1
   RWR conflicts have 1
   WRW conflicts have 0
   RWW conflicts have 0
   WWR conflicts have 0
   ...
   More details about the verification run can be found in the directory "./output".
   
   ```

    **NOTICE**: 

   1. We preset the time bound and memory limitation for each verification program to **300 s** and **4096 MB**, respectively.
   2. The original file of sample program `test.i` is `../Racebench-2.1/svp_simple_003_001.i`, based on the current directory `CPA4AV-Ourtool`.

4. Perform the experiments on the benchmarks

* The experiment for `Comparing CPA4AV with state-of-the-art tools on Racebench 2.1 `:

```bash
$ cd ./CPA4AV-Ourtool
$ ./fse-2023-exp.sh ./config/myAnalysis-interrupt-benchmark-racebench-with-interruption-points.properties ../Racebench-2.1
```

The output would be:

```bash
svp_simple_003_001.c: m1(RWR) = 1, m2(WRW) = 0, m3(RWW) = 0, m4(WWR) = 0, state = 448, time = 331
svp_simple_004_001.c: m1(RWR) = 1, m2(WRW) = 0, m3(RWW) = 0, m4(WWR) = 0, state = 207, time = 111
...
svp_simple_030_001.c: m1(RWR) = 0, m2(WRW) = 0, m3(RWW) = 1, m4(WWR) = 0, state = 88, time = 73
exit
```

After this, a result file can be obtained:

```bash
./CPA4AV-Ourtool/results.md
```

**NOTICE**:

1) The dataset `Racebench-2.1` only contains 12 interrupt-driven programs on which `intAtom`, `Rchecker` and our tool can execute normally and output valid results.
2) Other experiments, such as the experiment in ***Contribution of the Proposed Strategies*** and ***Precision Improvement with Configurable Strategies***, can be carried out by specifying the configuration file (e.g., `./config/myAnalysis-interrupt-benchmark-ldv-races-with-interruption-points.properties`, with the current directory `CPA4AV-Ourtool`) and the task directory (e.g., `../SV-COMP-2022-Benchmark/ldv-races`, with the current directory `CPA4AV-Ourtool`).

* Experiment for interruption point selection

```bash
$ cd ./CPA4AV-Ourtool
$ benchexec --no-container --tool-directory . CPA4AV-racebench.xml
```

The output would be:

```bash
2022-08-31 22:15:36 - INFO - Unable to find pqos_wrapper, please install it for cache allocation and monitoring if your CPU supports Intel RDT (cf. https://gitlab.com/sosy-lab/software/pqos-wrapper).
...
executing run set 'with-interruption-points.racebench'     (14 files)
22:15:36   starting   svp_simple_003_001.yml    
22:15:36   starting   svp_simple_004_001.yml    
22:15:39              svp_simple_004_001.yml    true                         2.67    2.68
22:15:39   starting   svp_simple_005_001.yml    
...

```

After the experiment, the results generated by `BenchExec` are stored under the folder `./CPA4AV-Ourtool/results/`, and there are four files listed as follows:

```bash
CPA4AV-racebench.2022-08-31_22-15-36.logfiles.zip	# it contains the intermediate output of each task.
CPA4AV-racebench.2022-08-31_22-15-36.results.txt		# brief information about the evaluation.
CPA4AV-racebench.2022-08-31_22-15-36.results.with-interruption-points.racebench.xml.bz2	# the details of each verification task.
CPA4AV-racebench.2022-08-31_22-15-36.results.without-interruption-points.racebench.xml.bz2
```

**NOTICE**: The four files above are used to count the memory consumed. The time consumed has been counted in step **The experiment for `Comparing CPA4AV with state-of-the-art tools on Racebench 2.1` **.

For generating the quantile plots of memory in logarithmic scale, we only need to use the file with extension `.bz2`.

```bash
$ cd ./CPA4AV-Ourtool/results && bunzip2 -d *.bz2 && cd ..
$ table-generator
```

 The tool `table-generator` will generate four files:

```bash
./CPA4AV-Ourtool/results/results.2022-08-31_22-31-04.diff.csv
./CPA4AV-Ourtool/results/results.2022-08-31_22-31-04.diff.html
./CPA4AV-Ourtool/results/results.2022-08-31_22-31-04.table.csv
./CPA4AV-Ourtool/results/results.2022-08-31_22-31-04.table.html
```

Now, the data in `*.table.csv` can be used to draw the quantile plots of memory.