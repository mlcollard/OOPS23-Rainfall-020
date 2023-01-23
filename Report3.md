<!-- {% raw %} -->
# Rainfall III: OOPS23-Rainfall-020

## Source

Space: `·` Tab: `-` [EOL](https://en.wikipedia.org/wiki/Newline) `$`

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
12 $
13 int main() {$
14 $
15 ····// input the hourly rainfall data$
16 ····const std::vector<double> rainfall{ std::istream_iterator<double>(std::cin),$
17 ········································std::istream_iterator<double>() };$
18 ····if (!rainfall.size()) {$
19 ········std::cerr << "Error: no rainfall data\n";$
20 ········return 1;$
21 ····}$
22 $
23 ····// calculate heaviest rainfall$
24 ····auto heaviest = rainfall[0];$
25 ····for (const auto rain: rainfall) {$
26 ········if (rain > heaviest)$
27 ············heaviest = rain;$
28 ····}$
29 $
30 ····// calculate the average rainfall$
31 ····auto total = rainfall[0];$
32 ····for (const auto rain: rainfall) {$
33 ········total += rain;$
34 ····}$
35 ····const auto average = total / rainfall.size();$
36 $
37 ····// output the rainfall report$
38 ····std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';$
39 ····std::cout << "|:----------------|----------------|" << '\n';$
40 ····std::cout << "| Average ········| ····" << std::left << std::setw(10) << std::fixed << std::setprecision(2) << average << " |" << '\n';$
41 ····std::cout << "| Heaviest ·······| ····" << std::left << std::setw(10) << heaviest << " |" << '\n';$
42 $
43 ····return 0;$
44 }$
```

## Style

Changed files:

```console
rainfall.cpp
```

Indentation Patterns for rainfall.cpp

```console
····
········
············
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
[ 50%] Building CXX object CMakeFiles/rainfall.dir/rainfall.cpp.o
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
Move local variable declarations to where first used
Rename variable t to total
Rename variable m to heaviest
Replace explicit type with auto
Separate calculation of [-heaviest and-] average {+and heaviest+}
Extract average calculation from output
Replace indexed for with range-based for
Add const to average
Replace input loop with std::istream_iterator
```

## Diff

% diff oracle/rainfall.cpp rainfall.cpp

```diff
15c15
<     // input hourly rainfall data
---
>     // input the hourly rainfall data
30,31c30,31
<     // calculate average rainfall
<     auto total = 0.0;
---
>     // calculate the average rainfall
>     auto total = rainfall[0];
35c35
<     const auto average = (total / rainfall.size());
---
>     const auto average = total / rainfall.size();
```

## Commits

## git checkout 25042b

% git show

```diff
commit 25042bc60efd5c0b3a2879b0c78ae2db5b96c8e3
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 19 14:43:16 2023 -0500

    Move local variable declarations to where first used

diff --git a/rainfall.cpp b/rainfall.cpp
index 899481c..206e97c 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -13,8 +13,6 @@ int main() {
 
     // input the hourly rainfall data
     std::vector<double> rainfall;
-    double t;
-    double m;
     double n;
     while (std::cin >> n) {
         rainfall.push_back(n);
@@ -25,8 +23,8 @@ int main() {
     }
 
     // calculate the average and heaviest rainfall
-    t = rainfall[0];
-    m = rainfall[0];
+    double t = rainfall[0];
+    double m = rainfall[0];
     for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
         t += rainfall[i];
         if (rainfall[i] > m)
```


% cmake ..

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
[ 50%] Building CXX object CMakeFiles/rainfall.dir/rainfall.cpp.o
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

## git checkout cca4ff

% git show

```diff
commit cca4ff8ce15868f60bd007561792a35778432f35
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 19 14:45:53 2023 -0500

    Rename variable t to total

diff --git a/rainfall.cpp b/rainfall.cpp
index 206e97c..298a3db 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -23,10 +23,10 @@ int main() {
     }
 
     // calculate the average and heaviest rainfall
-    double t = rainfall[0];
+    double total = rainfall[0];
     double m = rainfall[0];
     for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
-        t += rainfall[i];
+        total += rainfall[i];
         if (rainfall[i] > m)
             m = rainfall[i];
     }
@@ -34,7 +34,7 @@ int main() {
     // output the rainfall report
     std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
     std::cout << "|:----------------|----------------|" << '\n';
-    std::cout << "| Average         |     " << std::left << std::setw(10) << std::fixed << std::setprecision(2) << (t / rainfall.size()) << " |" << '\n';
+    std::cout << "| Average         |     " << std::left << std::setw(10) << std::fixed << std::setprecision(2) << (total / rainfall.size()) << " |" << '\n';
     std::cout << "| Heaviest        |     " << std::left << std::setw(10) << m << " |" << '\n';
 
     return 0;
```


% cmake ..

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
[ 50%] Building CXX object CMakeFiles/rainfall.dir/rainfall.cpp.o
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

## git checkout 910df9

% git show

```diff
commit 910df99a8ee259c946acc580cfee41c260ff9e7e
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 19 14:46:38 2023 -0500

    Rename variable m to heaviest

diff --git a/rainfall.cpp b/rainfall.cpp
index 298a3db..d69bd5b 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -24,18 +24,18 @@ int main() {
 
     // calculate the average and heaviest rainfall
     double total = rainfall[0];
-    double m = rainfall[0];
+    double heaviest = rainfall[0];
     for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
         total += rainfall[i];
-        if (rainfall[i] > m)
-            m = rainfall[i];
+        if (rainfall[i] > heaviest)
+            heaviest = rainfall[i];
     }
 
     // output the rainfall report
     std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
     std::cout << "|:----------------|----------------|" << '\n';
     std::cout << "| Average         |     " << std::left << std::setw(10) << std::fixed << std::setprecision(2) << (total / rainfall.size()) << " |" << '\n';
-    std::cout << "| Heaviest        |     " << std::left << std::setw(10) << m << " |" << '\n';
+    std::cout << "| Heaviest        |     " << std::left << std::setw(10) << heaviest << " |" << '\n';
 
     return 0;
 }
```


% cmake ..

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
[ 50%] Building CXX object CMakeFiles/rainfall.dir/rainfall.cpp.o
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

## git checkout 26a019

% git show

```diff
commit 26a0197e4adf889b0d613a3b232372d8fd766cea
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 19 14:50:20 2023 -0500

    Replace explicit type with auto

diff --git a/rainfall.cpp b/rainfall.cpp
index d69bd5b..5b0fc5f 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -23,8 +23,8 @@ int main() {
     }
 
     // calculate the average and heaviest rainfall
-    double total = rainfall[0];
-    double heaviest = rainfall[0];
+    auto total = rainfall[0];
+    auto heaviest = rainfall[0];
     for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
         total += rainfall[i];
         if (rainfall[i] > heaviest)
```


% cmake ..

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
[ 50%] Building CXX object CMakeFiles/rainfall.dir/rainfall.cpp.o
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

## git checkout dd7192

% git show

```diff
commit dd7192cf1c9b8776794685a845bc283d05bd3b9a
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 19 14:56:07 2023 -0500

    Separate calculation of heaviest and average

diff --git a/rainfall.cpp b/rainfall.cpp
index 5b0fc5f..aad3c57 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -22,15 +22,19 @@ int main() {
         return 1;
     }
 
-    // calculate the average and heaviest rainfall
-    auto total = rainfall[0];
+    // calculate heaviest rainfall
     auto heaviest = rainfall[0];
     for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
-        total += rainfall[i];
         if (rainfall[i] > heaviest)
             heaviest = rainfall[i];
     }
 
+    // calculate the average rainfall
+    auto total = rainfall[0];
+    for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
+        total += rainfall[i];
+    }
+
     // output the rainfall report
     std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
     std::cout << "|:----------------|----------------|" << '\n';
```


% cmake ..

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
[ 50%] Building CXX object CMakeFiles/rainfall.dir/rainfall.cpp.o
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

## git checkout dff5bd

% git show

```diff
commit dff5bde5dcc1b1a023219aee5f108a28875df096
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 19 14:58:48 2023 -0500

    Extract average calculation from output

diff --git a/rainfall.cpp b/rainfall.cpp
index aad3c57..c7c7425 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -34,11 +34,12 @@ int main() {
     for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
         total += rainfall[i];
     }
+    auto average = total / rainfall.size();
 
     // output the rainfall report
     std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
     std::cout << "|:----------------|----------------|" << '\n';
-    std::cout << "| Average         |     " << std::left << std::setw(10) << std::fixed << std::setprecision(2) << (total / rainfall.size()) << " |" << '\n';
+    std::cout << "| Average         |     " << std::left << std::setw(10) << std::fixed << std::setprecision(2) << average << " |" << '\n';
     std::cout << "| Heaviest        |     " << std::left << std::setw(10) << heaviest << " |" << '\n';
 
     return 0;
```


% cmake ..

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
[ 50%] Building CXX object CMakeFiles/rainfall.dir/rainfall.cpp.o
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

## git checkout 451497

% git show

```diff
commit 451497cb4697dc5da9e1849ece5967d457ed939e
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 19 15:03:34 2023 -0500

    Replace indexed for with range-based for

diff --git a/rainfall.cpp b/rainfall.cpp
index c7c7425..3dc2166 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -24,15 +24,15 @@ int main() {
 
     // calculate heaviest rainfall
     auto heaviest = rainfall[0];
-    for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
-        if (rainfall[i] > heaviest)
-            heaviest = rainfall[i];
+    for (const auto rain: rainfall) {
+        if (rain > heaviest)
+            heaviest = rain;
     }
 
     // calculate the average rainfall
     auto total = rainfall[0];
-    for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
-        total += rainfall[i];
+    for (const auto rain: rainfall) {
+        total += rain;
     }
     auto average = total / rainfall.size();
 
```


% cmake ..

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
[ 50%] Building CXX object CMakeFiles/rainfall.dir/rainfall.cpp.o
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

## git checkout 23535e

% git show

```diff
commit 23535e9a7bb9cab865aa95ef76520feaa0b14c0d
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 19 15:05:16 2023 -0500

    Add const to average

diff --git a/rainfall.cpp b/rainfall.cpp
index 3dc2166..9182767 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -34,7 +34,7 @@ int main() {
     for (const auto rain: rainfall) {
         total += rain;
     }
-    auto average = total / rainfall.size();
+    const auto average = total / rainfall.size();
 
     // output the rainfall report
     std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
```


% cmake ..

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
[ 50%] Building CXX object CMakeFiles/rainfall.dir/rainfall.cpp.o
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

## git checkout b480d6

% git show

```diff
commit b480d681ea74a5a9adf7b09e26ca7a5cc3b2a92d
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 19 15:09:37 2023 -0500

    Replace input loop with std::istream_iterator

diff --git a/rainfall.cpp b/rainfall.cpp
index 9182767..62e2db6 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -7,16 +7,14 @@
 
 #include <iostream>
 #include <iomanip>
+#include <iterator>
 #include <vector>
 
 int main() {
 
     // input the hourly rainfall data
-    std::vector<double> rainfall;
-    double n;
-    while (std::cin >> n) {
-        rainfall.push_back(n);
-    }
+    const std::vector<double> rainfall{ std::istream_iterator<double>(std::cin),
+                                        std::istream_iterator<double>() };
     if (!rainfall.size()) {
         std::cerr << "Error: no rainfall data\n";
         return 1;
```


% cmake ..

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
[ 50%] Building CXX object CMakeFiles/rainfall.dir/rainfall.cpp.o
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


<!-- {% endraw %} -->
