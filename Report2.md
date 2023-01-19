<!-- {% raw %} -->
# Rainfall II: OOPS23-Rainfall-020

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
10 #include <vector>$
11 $
12 int main() {$
13 $
14 ····// input the hourly rainfall data$
15 ····std::vector<double> rainfall;$
16 ····double t;$
17 ····double m;$
18 ····double n;$
19 ····while (std::cin >> n) {$
20 ········rainfall.push_back(n);$
21 ····}$
22 ····if (!rainfall.size()) {$
23 ········std::cerr << "Error: no rainfall data\n";$
24 ········return 1;$
25 ····}$
26 $
27 ····// calculate the average and heaviest rainfall$
28 ····t = rainfall[0];$
29 ····m = rainfall[0];$
30 ····for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {$
31 ········t += rainfall[i];$
32 ········if (rainfall[i] > m)$
33 ············m = rainfall[i];$
34 ····}$
35 $
36 ····// output the rainfall report$
37 ····std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';$
38 ····std::cout << "|:----------------|----------------|" << '\n';$
39 ····std::cout << "| Average ········| ····" << std::left << std::setw(10) << std::fixed << std::setprecision(2) << (t / rainfall.size()) << " |" << '\n';$
40 ····std::cout << "| Heaviest ·······| ····" << std::left << std::setw(10) << m << " |" << '\n';$
41 $
42 ····return 0;$
43 }$
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
Add a newline to the error output
Separate each section of code with a single newline
Comment each section of code
Separate each variable into its own declaration statement
Replace float with double
```

## Diff

% diff oracle/rainfall.cpp rainfall.cpp

```diff
14c14
<     // input hourly rainfall data
---
>     // input the hourly rainfall data
27c27
<     // calculate average and heaviest rainfall
---
>     // calculate the average and heaviest rainfall
```

## Commits

## git checkout acabab

% git show

```diff
commit acabab32466ff512b6f6fe8aa200e5a48e128531
Author: Michael L. Collard <collard@uakron.edu>
Date:   Tue Jan 17 15:01:05 2023 -0500

    Add a newline to the error output

diff --git a/rainfall.cpp b/rainfall.cpp
index 01c22e2..f8f6f1b 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -16,7 +16,7 @@ int main() {
         rainfall.push_back(n);
     }
     if (!rainfall.size()) {
-        std::cerr << "Error: no rainfall data";
+        std::cerr << "Error: no rainfall data\n";
         return 1;
     }
     t = rainfall[0];
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

## git checkout 20a405

% git show

```diff
commit 20a405af335e120e394584830c3d9f36bbd23bd8
Author: Michael L. Collard <collard@uakron.edu>
Date:   Tue Jan 17 15:04:02 2023 -0500

    Separate each section of code with a single newline

diff --git a/rainfall.cpp b/rainfall.cpp
index f8f6f1b..31e31e1 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -19,6 +19,7 @@ int main() {
         std::cerr << "Error: no rainfall data\n";
         return 1;
     }
+
     t = rainfall[0];
     m = rainfall[0];
     for (std::vector<float>::size_type i = 1; i < rainfall.size(); ++i) {
@@ -26,6 +27,7 @@ int main() {
         if (rainfall[i] > m)
             m = rainfall[i];
     }
+
     std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
     std::cout << "|:----------------|----------------|" << '\n';
     std::cout << "| Average         |     " << std::left << std::setw(10) << std::fixed << std::setprecision(2) << (t / rainfall.size()) << " |" << '\n';
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

## git checkout 05a32f

% git show

```diff
commit 05a32f0886012ad6e966ac376095da78811a0c5b
Author: Michael L. Collard <collard@uakron.edu>
Date:   Tue Jan 17 15:08:15 2023 -0500

    Comment each section of code

diff --git a/rainfall.cpp b/rainfall.cpp
index 31e31e1..4306535 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -10,6 +10,8 @@
 #include <vector>
 
 int main() {
+
+    // input the hourly rainfall data
     std::vector<float> rainfall;
     float t, m, n;
     while (std::cin >> n) {
@@ -20,6 +22,7 @@ int main() {
         return 1;
     }
 
+    // calculate the average and heaviest rainfall
     t = rainfall[0];
     m = rainfall[0];
     for (std::vector<float>::size_type i = 1; i < rainfall.size(); ++i) {
@@ -28,6 +31,7 @@ int main() {
             m = rainfall[i];
     }
 
+    // output the rainfall report
     std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
     std::cout << "|:----------------|----------------|" << '\n';
     std::cout << "| Average         |     " << std::left << std::setw(10) << std::fixed << std::setprecision(2) << (t / rainfall.size()) << " |" << '\n';
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

## git checkout 4668ee

% git show

```diff
commit 4668ee36e773694c69a91106f9a1a2f35abe2d28
Author: Michael L. Collard <collard@uakron.edu>
Date:   Tue Jan 17 15:11:23 2023 -0500

    Separate each variable into its own declaration statement

diff --git a/rainfall.cpp b/rainfall.cpp
index 4306535..d2d2b44 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -13,7 +13,9 @@ int main() {
 
     // input the hourly rainfall data
     std::vector<float> rainfall;
-    float t, m, n;
+    float t;
+    float m;
+    float n;
     while (std::cin >> n) {
         rainfall.push_back(n);
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

## git checkout 17f0f8

% git show

```diff
commit 17f0f80fa0a7e3172e6b5b2f8f7aeab96543c921
Author: Michael L. Collard <collard@uakron.edu>
Date:   Tue Jan 17 15:14:31 2023 -0500

    Replace float with double

diff --git a/rainfall.cpp b/rainfall.cpp
index d2d2b44..899481c 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -12,10 +12,10 @@
 int main() {
 
     // input the hourly rainfall data
-    std::vector<float> rainfall;
-    float t;
-    float m;
-    float n;
+    std::vector<double> rainfall;
+    double t;
+    double m;
+    double n;
     while (std::cin >> n) {
         rainfall.push_back(n);
     }
@@ -27,7 +27,7 @@ int main() {
     // calculate the average and heaviest rainfall
     t = rainfall[0];
     m = rainfall[0];
-    for (std::vector<float>::size_type i = 1; i < rainfall.size(); ++i) {
+    for (std::vector<double>::size_type i = 1; i < rainfall.size(); ++i) {
         t += rainfall[i];
         if (rainfall[i] > m)
             m = rainfall[i];
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
