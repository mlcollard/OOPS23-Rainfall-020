<!-- {% raw %} -->
# Rainfall IV: OOPS23-Rainfall-020

## Source

Space: `·` Tab: `-` [EOL](https://en.wikipedia.org/wiki/Newline) `$`

### rainfall.cpp

```C++
 1 /*$
 2 ····rainfall.cpp$
 3 $
 4 ····Rainfall report. Inputs are rain amounts per hour. Output is the average$
 5 ····and heaviest hourly rainfall.$
 6 */$
 7 $
 8 #include <iostream>$
 9 #include <iomanip>$
10 #include <iterator>$
11 #include <vector>$
12 #include "Aggregate.hpp"$
13 $
14 int main() {$
15 $
16 ····// input the hourly rainfall data$
17 ····const std::vector<double> rainfall{ std::istream_iterator<double>(std::cin),$
18 ········································std::istream_iterator<double>() };$
19 ····if (!rainfall.size()) {$
20 ········std::cerr << "Error: no rainfall data\n";$
21 ········return 1;$
22 ····}$
23 $
24 ····// calculate heaviest rainfall$
25 ····auto heaviest = max(rainfall);$
26 $
27 ····// calculate the average rainfall$
28 ····const auto average = avg(rainfall);$
29 $
30 ····// output the rainfall report$
31 ····std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';$
32 ····std::cout << "|:----------------|----------------|" << '\n';$
33 ····std::cout << "| Average ········| ····" << std::left << std::setw(10) << std::fixed << std::setprecision(2) << average << " |" << '\n';$
34 ····std::cout << "| Heaviest ·······| ····" << std::left << std::setw(10) << heaviest << " |" << '\n';$
35 $
36 ····return 0;$
37 }$
```

### Aggregate.hpp

```C++
 1 /*$
 2 ····Aggregate.hpp$
 3 $
 4 ····Include file for aggregate functions$
 5 */$
 6 $
 7 #ifndef INCLUDED_AGGREGATE_HPP$
 8 #define INCLUDED_AGGREGATE_HPP$
 9 $
10 #include <vector>$
11 $
12 // maximum of the data$
13 double max(const std::vector<double>& data);$
14 $
15 // average of the data$
16 double avg(const std::vector<double>& data);$
17 $
18 #endif$
```

### Aggregate.cpp

```C++
 1 /*$
 2 ····Aggregate.cpp$
 3 $
 4 ····Implementation file for aggregate functions$
 5 */$
 6 $
 7 #include "Aggregate.hpp"$
 8 #include <numeric>$
 9 #include <algorithm>$
10 $
11 // maximum of the data$
12 double max(const std::vector<double>& data) {$
13 $
14 ····return *std::max_element(data.begin(), data.end());$
15 }$
16 $
17 // average of the data$
18 double avg(const std::vector<double>& data) {$
19 $
20 ····auto total = std::accumulate(data.begin(), data.end(), 0.0);$
21 $
22 ····return total / data.size();$
23 }$
```

## Style

Changed files:

```console
Aggregate.cpp
Aggregate.hpp
CMakeLists.txt
Report3.md
rainfall.cpp
```

Indentation Patterns for rainfall.cpp

```console
····
········
········································
```

## Build
% mkdir build; cd build; cmake ..

```console
-- The C compiler identification is GNU 11.3.0
-- The CXX compiler identification is GNU 11.3.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Check output uses diff: /usr/bin/diff
-- Configuring done
-- Generating done
-- Build files have been written to: /Build
```
% make

```console
[ 33%] Building CXX object CMakeFiles/rainfall.dir/rainfall.cpp.o
[ 66%] Building CXX object CMakeFiles/rainfall.dir/Aggregate.cpp.o
[100%] Linking CXX executable rainfall
[100%] Built target rainfall
```

% make run

```console
[100%] Built target rainfall
| Hourly Rainfall | Inches in 100s |
|:----------------|----------------|
| Average         |     0.04       |
| Heaviest        |     1.04       |
[100%] Built target run
```

% make check

```console
[100%] Built target rainfall
[100%] Built target check
```


## Commit Messages

```console
4185ca6 Initial commit
8816ce1 Add a header comment
712f617 Add a final return to main()
d42b3cf Remove using namespace std
4d9f39b Change error output from standard output to standard error
acabab3 Add a newline to the error output
20a405a Separate each section of code with a single newline
05a32f0 Comment each section of code
4668ee3 Separate each variable into its own declaration statement
17f0f80 Replace float with double
25042bc Move local variable declarations to where first used
cca4ff8 Rename variable t to total
910df99 Rename variable m to heaviest
26a0197 Replace explicit type with auto
dd7192c Separate calculation of heaviest and average
dff5bde Extract average calculation from output
451497c Replace indexed for with range-based for
23535e9 Add const to average
b480d68 Replace input loop with std::istream_iterator
6f580d9 Add generated report for Rainfall III
ccb921f Add max() function
70aec08 Replace inline max code with max()
61d1378 Extract avg()
c7fa77a Add Aggregate files to project
fd8ee11 Extract max() declaration into Aggregate include file
38c0a7b Extract max() definition into Aggregate definition file
bb0e106 Add avg() declaration to Aggregate include file
eaa33e6 Move avg() definition to Aggregate implementation file
825152e Replace loop for total with call to std::accumulate()
2ef217e Replace max loop with std::max_element()
```

## Diff

% diff oracle/rainfall.cpp rainfall.cpp

```diff
11a12
> #include "Aggregate.hpp"
15c16
<     // input hourly rainfall data
---
>     // input the hourly rainfall data
24,28c25
<     auto heaviest = rainfall[0];
<     for (const auto rain: rainfall) {
<         if (rain > heaviest)
<             heaviest = rain;
<     }
---
>     auto heaviest = max(rainfall);
30,35c27,28
<     // calculate average rainfall
<     auto total = 0.0;
<     for (const auto rain: rainfall) {
<         total += rain;
<     }
<     const auto average = (total / rainfall.size());
---
>     // calculate the average rainfall
>     const auto average = avg(rainfall);
```

% diff oracle/Aggregate.cpp Aggregate.cpp

```diff
20c20
<     const auto total = std::accumulate(data.begin(), data.end(), 0.0);
---
>     auto total = std::accumulate(data.begin(), data.end(), 0.0);
```

% diff oracle/Aggregate.hpp Aggregate.hpp

```diff
```
<!-- {% endraw %} -->
