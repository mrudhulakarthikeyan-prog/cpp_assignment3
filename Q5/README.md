# Q5 – Increment, Comparison and Subscript Operators
Run main.cpp and predict_output.cpp. Write the exact prediction in Evidence/Predictions
before running predict_output.cpp. Main demonstrates prefix/postfix values, comparisons,
59:59 rollover, valid playlist access and checked invalid indexes. For the required
10,000,000 benchmark, compile at -O0 and -O2 and record actual timings. Compare checked
operator[] with at() (throws) and unchecked access; all are O(1), checked access adds
a bounds comparison.
