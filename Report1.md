<!-- {% raw %} -->
# Rainfall I: OOPS23-Rainfall-020

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
13 ····std::vector<float> rainfall;$
14 ····float t, m, n;$
15 ····while (std::cin >> n) {$
16 ········rainfall.push_back(n);$
17 ····}$
18 ····if (!rainfall.size()) {$
19 ········std::cout << "Error: no rainfall data";$
20 ········return 1;$
21 ····}$
22 ····t = rainfall[0];$
23 ····m = rainfall[0];$
24 ····for (std::vector<float>::size_type i = 1; i < rainfall.size(); ++i) {$
25 ········t += rainfall[i];$
26 ········if (rainfall[i] > m)$
27 ············m = rainfall[i];$
28 ····}$
29 ····std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';$
30 ····std::cout << "|:----------------|----------------|" << '\n';$
31 ····std::cout << "| Average ········| ····" << std::left << std::setw(10) << std::fixed << std::setprecision(2) << (t / rainfall.size()) << " |" << '\n';$
32 ····std::cout << "| Heaviest ·······| ····" << std::left << std::setw(10) << m << " |" << '\n';$
33 $
34 ····return 0;$
35 }$
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
Add a header comment
Add a final return to main()
Remove using namespace std
```

## Commits
## git checkout 8816ce

% git show

```diff
commit 8816ce139b0c117b9000878d002c7f900d369e01
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 12 15:06:30 2023 -0500

    Add a header comment

diff --git a/rainfall.cpp b/rainfall.cpp
index 3b0651c..57decdb 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -1,3 +1,10 @@
+/*
+    rainfall.cpp
+
+    Rainfall report. Inputs are rain amounts per hour. Output is the average
+    and heaviest hourly rainfall.
+*/
+
 #include <iostream>
 #include <iomanip>
 #include <vector>
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

% diff oracle/rainfall.cpp rainfall.cpp

```diff
```

## git checkout 712f61

% git show

```diff
commit 712f61713c1ea2dc1b24a61c3e4fead58c2ed111
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 12 15:11:21 2023 -0500

    Add a final return to main()

diff --git a/rainfall.cpp b/rainfall.cpp
index 57decdb..0a3469a 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -32,4 +32,6 @@ int main() {
     cout << "|:----------------|----------------|" << '\n';
     cout << "| Average         |     " << left << setw(10) << fixed << setprecision(2) << (t / rainfall.size()) << " |" << '\n';
     cout << "| Heaviest        |     " << left << setw(10) << m << " |" << '\n';
+
+    return 0;
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

% diff oracle/rainfall.cpp rainfall.cpp

```diff
```

## git checkout d42b3c

% git show

```diff
commit d42b3cff88de64d2fe1b2b3ebb61d8b43aea83c3
Author: Michael L. Collard <collard@uakron.edu>
Date:   Thu Jan 12 15:14:23 2023 -0500

    Remove using namespace std

diff --git a/rainfall.cpp b/rainfall.cpp
index 0a3469a..e855a9a 100644
--- a/rainfall.cpp
+++ b/rainfall.cpp
@@ -9,29 +9,27 @@
 #include <iomanip>
 #include <vector>
 
-using namespace std;
-
 int main() {
-    vector<float> rainfall;
+    std::vector<float> rainfall;
     float t, m, n;
-    while (cin >> n) {
+    while (std::cin >> n) {
         rainfall.push_back(n);
     }
     if (!rainfall.size()) {
-        cout << "Error: no rainfall data";
+        std::cout << "Error: no rainfall data";
         return 1;
     }
     t = rainfall[0];
     m = rainfall[0];
-    for (vector<float>::size_type i = 1; i < rainfall.size(); ++i) {
+    for (std::vector<float>::size_type i = 1; i < rainfall.size(); ++i) {
         t += rainfall[i];
         if (rainfall[i] > m)
             m = rainfall[i];
     }
-    cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
-    cout << "|:----------------|----------------|" << '\n';
-    cout << "| Average         |     " << left << setw(10) << fixed << setprecision(2) << (t / rainfall.size()) << " |" << '\n';
-    cout << "| Heaviest        |     " << left << setw(10) << m << " |" << '\n';
+    std::cout << "| Hourly Rainfall | Inches in 100s |" << '\n';
+    std::cout << "|:----------------|----------------|" << '\n';
+    std::cout << "| Average         |     " << std::left << std::setw(10) << std::fixed << std::setprecision(2) << (t / rainfall.size()) << " |" << '\n';
+    std::cout << "| Heaviest        |     " << std::left << std::setw(10) << m << " |" << '\n';
 
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

% diff oracle/rainfall.cpp rainfall.cpp

```diff
```


<!-- {% endraw %} -->
