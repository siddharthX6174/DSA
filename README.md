

# C++ Competitive Programming Collection

A curated collection of C++ solutions, templates, and notes for competitive programming practice and contests.

## Repository Overview

- **Purpose:** Practice problems, templates, and reference implementations for algorithms and data structures.
- **Primary language:** C++ (various standards; mostly C++11/14/17/20)
- **Typical use:** Study templates, copy minimal snippets into contest submissions, and track problem solutions.

## Repository Structure

Key folders (top-level):


 Note: The repository layout is organic; browse folders to find topic-specific examples.

 ## Index of Problems (by folder)

 Browse the folders below to find problem solutions and templates. This is a concise index of the main top-level folders and representative files/subfolders.

 - `BEPO/` — [test.cpp](BEPO/test.cpp), [Array/](BEPO/Array/)
 - `LeetVirtual/` — [1.cpp](LeetVirtual/1.cpp), [3.cpp](LeetVirtual/3.cpp), [stone_game_VII.cpp](LeetVirtual/stone_game_VII.cpp), [220/](LeetVirtual/220/), [221/](LeetVirtual/221/), [222/](LeetVirtual/222/), [486/](LeetVirtual/486/)
 - `Practise sessions/` — [1_subarray_sum_0_count.cpp](Practise%20sessions/1_subarray_sum_0_count.cpp), [leet_2381_shifting_letters.cpp](Practise%20sessions/leet_2381_shifting_letters.cpp), [sliding Window/](Practise%20sessions/sliding%20Window/)
 - `test/` — [1.cpp](test/1.cpp), [2.cpp](test/2.cpp), [5.cpp](test/5.cpp), [8.cpp](test/8.cpp)
 - `Codeforces/` — [03oct25/](Codeforces/03oct25/), [17jan26/](Codeforces/17jan26/)
 - `New Start/` — [Containers/](New%20Start/Containers/), [Graph/](New%20Start/Graph/), [Graph02/](New%20Start/Graph02/)
 - `DATA STRUCTURE/` — [Array/](DATA%20STRUCTURE/Array/), [Greedy/](DATA%20STRUCTURE/Greedy/), [Stack/](DATA%20STRUCTURE/Stack/), [String/](DATA%20STRUCTURE/String/), [TREE/](DATA%20STRUCTURE/TREE/)
 - `Revesion/` — [Array/](Revesion/Array/), [Graph/](Revesion/Graph/), [Recursion/](Revesion/Recursion/), [STL/](Revesion/STL/)
 - `Launchpad(april)/` — lecture notes and code: [Launchpad(april)/](Launchpad(april)/)
 - `TCS NQT/` — [Array/](TCS%20NQT/Array/)
 - `COMPETITIVE CODING/` — [01Basic/](COMPETITIVE%20CODING/01Basic/)
 - Root files: [input.in](input.in), [output.out](output.out)

 If you'd like, I can expand this index into a full tree (recursive) or add direct file links with short descriptions for each solution.
## Getting Started

Prerequisites:

- A C++ compiler (g++, clang++)
- Recommended: `g++` with at least C++17 support

Compile a single file (example):

```bash
g++ -std=c++17 -O2 -pipe path/to/file.cpp -o file.exe
```

Run with input from `input.in` (if present):

```bash
./file.exe < input.in
```

Compile multiple files or a folder (example):

```bash
g++ -std=c++17 -O2 -pipe folder/*.cpp -o program.exe
```

Windows (MinGW) example:

```powershell
g++ -std=c++17 -O2 -pipe "test/1.cpp" -o test.exe
.\test.exe < input.in
```

## Conventions & Tips

- Use fast I/O (`ios::sync_with_stdio(false); cin.tie(nullptr);`) for contest problems.
- Prefer concise templates: keep helper functions small and modular.
- Put reusable snippets (segment tree, DSU, Dijkstra) in a folder for quick copy/paste.
- Name files clearly (e.g., `01_arr.cpp`, `02_adjacency.cpp`) to reflect problem/topic.

## Contributing

1. Add new solutions under an appropriate folder.
2. Keep filenames and folder names descriptive.
3. If you add long explanations, include a short comment header in the source file.

## License

This repository is provided as-is for learning and practice. If you want an explicit license, consider adding a `LICENSE` file (e.g., MIT).

## Contact

If you have questions or want to suggest improvements, open an issue or reach out to the repository owner.

---

Happy coding!

