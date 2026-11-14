# Green Efficiency Analysis

## Measurement Methodology

All programs were compiled with gcc using the flags -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long and executed on the same machine, in the same terminal session, one after another. Time was measured inside each program with clock() from time.h, converted to seconds by dividing by CLOCKS_PER_SEC. Because clock() reports processor time used by the process, it reflects CPU work rather than wall-clock waiting. Each program was executed three times to observe variability, and averages were computed for the comparison experiment.

For the instrumentation lab, each phase (build, process, reduce) was timed around its own function call only, so no printing or setup is included inside a phase. TOTAL was measured from just before build_dataset() to just after reduce_checksum(), which guarantees that TOTAL is greater than or equal to every sub-measurement.

## Observed Performance Differences

The baseline loop of 100,000,000 iterations took 0.178992, 0.148796 and 0.145198 seconds. The values are close but not identical, which shows that even a deterministic computation has some run-to-run variability, often largest on the first run.

In the algorithm comparison, both implementations scan the same 50,000-element array for even numbers, but their cost was very different (the naive version re-counts each prefix and prints 625025000, the single-pass version prints 25000). The naive version took 1.213582, 1.239002 and 1.211163 seconds (average 1.221249 s), while the single-pass version took 0.000044, 0.000058 and 0.000043 seconds (average 0.000048 s). In other words, the naive implementation is ~25443 times slower than the single-pass implementation. This matches the theory: the naive algorithm re-scans the array for every element (O(n^2), about 1.25 billion checks), while the single-pass algorithm reads each element once (O(n), 50,000 checks).

In the instrumentation lab, one run reported TOTAL 0.000557 s, BUILD_DATA 0.000252 s, PROCESS 0.000195 s and REDUCE 0.000107 s. TOTAL across the three runs was 0.000557, 0.000705 and 0.000514 seconds. All phases are linear over 50,000 elements, so each completes in a very short time, close to the resolution limit of clock().

## Relation Between Runtime and Energy Consumption

This project did not measure power in watts, so runtime is used as a proxy. When the CPU is busy for longer, it stays in a high-power state for longer, so total energy generally grows with execution time. Under that assumption, the naive algorithm, which kept the CPU busy for about 1.221249 seconds instead of 0.000048 seconds, would consume far more energy for the same counting task. Repeated millions of times on servers, this difference becomes significant in electricity use and carbon emissions.

## Limitations of the Experiment

First, runtime is only an indirect indicator of energy; real power draw depends on CPU frequency scaling, cores used, memory activity and hardware. Second, clock() has limited resolution, so very fast phases, such as the single-pass algorithm and the instrumentation phases, can show values near or equal to zero, which makes exact ratios unreliable. Third, only three runs were made on one machine, with background processes possibly affecting results, as seen in the slower first baseline run. Finally, no compiler optimization level was specified, so results could change with -O2.

## Practical Engineering Takeaway

The largest efficiency gain came from choosing a better algorithm, not from micro-tuning: moving from O(n^2) to O(n) removed almost all of the work for the same counting task. Engineers should measure before optimizing, repeat measurements to account for variability, and treat lower CPU time as a practical way to reduce energy use. Efficient code is not only faster, it is also a more responsible use of shared computing resources.
