_This project has been created as part of the 42 curriculum by mahendri, ainrakot._

# push_swap

## Description

`push_swap` is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of unique integers using two stacks (`a` and `b`) and a restricted set of stack operations, while minimizing the total number of operations produced.

The program analyzes the input, measures the disorder of the stack, selects the most appropriate sorting strategy, and outputs the sequence of operations that sorts stack `a` in ascending order with the smallest number at the top.

A bonus `checker` program is also provided: it reads a list of operations from stdin and verifies whether they correctly sort the original stack.

## NB

- No duplicate integers are allowed in the input.
- All integers must fit within the 32-bit signed integer range (`INT_MIN` to `INT_MAX`).
- Global variables are forbidden.
- The project must comply with the 42 Norm.
- Memory leaks are not tolerated; all heap-allocated memory is freed before exit.
- The `checker` bonus is only evaluated if the mandatory part passes all benchmarks without exception.

## Instructions

### Prerequisites

- `cc` (C compiler)
- `make`
- `libft` and `ft_printf` are embedded in the repository under `ft_printf/`

### Compilation / Build

```bash
# Build push_swap
make

# Build checker (bonus)
make bonus

# Clean object files
make clean

# Full clean (objects + binaries)
make fclean

# Rebuild from scratch
make re
```

### Available Commands

- `make` - Builds the `push_swap` binary
- `make bonus` - Builds the `checker` binary
- `make clean` - Removes all `.o` object files
- `make fclean` - Removes object files and compiled binaries
- `make re` - Runs `fclean` then `all`

### Using the Project / Library

**push_swap** takes a list of integers as arguments (first argument = top of stack) and an optional strategy flag. It prints the operation sequence to stdout.

**checker** takes the same list of integers as arguments, reads operations from stdin (one per line), executes them, and prints `OK` or `KO` to stdout. It prints `Error` to stderr on invalid input or invalid operations.

**Strategy flags (optional, one at a time):**

| Flag | Algorithm | Complexity |
|---|---|---|
| `--simple` | Selection sort adaptation | O(n²) |
| `--medium` | Chunk-based sorting | O(n√n) |
| `--complex` | Radix sort (LSD binary) | O(n log n) |
| `--adaptive` | Adaptive (default, selected by disorder) | varies |

**Benchmark flag (optional, combinable with strategy flags):**

| Flag | Effect |
|---|---|
| `--bench` | Prints disorder, strategy used, total ops, and per-operation counts to stderr |

### Example Usage

```bash
# Basic sort (adaptive by default)
./push_swap 3 2 1 0

# Force simple O(n²) strategy
./push_swap --simple 5 4 3 2 1

# Force complex O(n log n) strategy
./push_swap --complex 4 67 3 87 23

# Count operations on 5 elements
ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l

# Verify correctness with checker
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker $ARG

# Run with benchmark output, redirect ops to checker
ARG="4 67 3 87 23"; ./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker $ARG
cat bench.txt

# Large input benchmark
shuf -i 0-9999 -n 500 > args.txt; ./push_swap $(cat args.txt)

# Error cases
./push_swap 1 2 abc 4						# → Error (non-integer)
./push_swap 1 2 2147483648					# → Error (overflow)
./push_swap 3 2 3							# → Error (duplicate)
./push_swap									# → (no output, no error)
./push_swap 42								# → (already sorted, no output)
./push_swap 8 1 2 4 --invalid				# → Error (invalid flag)
./push_swap 8 1 2 4 --simple --complex		# → Error (invalid flag)
```

**checker examples:**

```bash
./push_swap 3 2 1 0 | ./checker 3 2 1 0
# → OK

./checker 3 2 one 0
# → Error
```

## Algorithm Design

### Disorder Metric

Before selecting a strategy, the program computes a **disorder score** between `0` and `10000` (scaled from `0.0` to `1.0`). It counts all inverted pairs in stack `a` — pairs where a larger number appears before a smaller one — and divides by the total number of pairs:

```
disorder = (inverted_pairs / total_pairs) * 10000
```

A disorder of `0` means the stack is already sorted. A disorder of `10000` means the stack is fully reversed.

---

### Strategy 1 — Simple: Selection Sort Adaptation — O(n²)

Selected when `--simple` is used or when `disorder < 2000` in adaptive mode.

The algorithm extracts elements from stack `a` one by one in sorted order by rotating `a` to bring the minimum to the top, pushing it to `b`, and repeating until `a` is empty. It then pushes everything back from `b` to `a`. For each element, it scans the entire remaining stack to find the minimum index, making each extraction O(n) and the total O(n²).

The rotation direction (ra vs rra) is chosen each time based on which half of the stack the target element is in, minimizing moves per extraction.

**Space complexity:** O(n²) — the stack itself. No auxiliary arrays beyond the index structure.

---

### Strategy 2 — Medium: Chunk-Based Sorting — O(n√n)

Selected when `--medium` is used or when `2000 ≤ disorder < 5000` in adaptive mode.

The stack is divided into `√n` chunks of equal size using the index. In each pass, all elements belonging to the current chunk (those with index ≤ current sequence threshold) are pushed to `b` by rotating through `a`. Once all chunks are transferred to `b`, elements are pulled back to `a` by repeatedly finding and extracting the maximum from `b`.

Each pass over `a` costs O(n) rotations, and there are O(√n) passes, giving O(n√n) total operations.

**Space complexity:** O(√n).

---

### Strategy 3 — Complex: Radix Sort (LSD Binary) — O(n log n)

Selected when `--complex` is used or when `disorder ≥ 5000` in adaptive mode.

Elements are first indexed (0 to n-1) so all values are non-negative integers. The algorithm then performs a binary LSD (Least Significant Bit) radix sort: for each bit position from LSB to MSB, elements with bit = 0 are pushed to `b` and elements with bit = 1 stay in `a`. After processing all elements in `a`, everything in `b` is pushed back to `a`. This is repeated for `log2(n)` bit positions.

Total operations: O(n) per bit × O(log n) bits = O(n log n).

**Space complexity:** O(n log n).

---

### Strategy 4 — Special Case: Fully Inverted Stack — O(n)

When `disorder = 10000` (fully reversed stack), a dedicated solver is used instead of the adaptive selection. It reverse-rotates all elements from `a` into `b` (preserving order via `rra` + `pb`), then pushes them all back to `a` (`pa`), which produces a sorted `a` in exactly `2n` operations.

---

### Adaptive Strategy — Threshold Rationale

| Disorder Range | Strategy Selected | Rationale |
|---|---|---|
| `1` (== 10000) | Invert (O(n)) | Perfect reversal has a trivial O(n) solution |
| `< 0.20` (< 2000) | Simple O(n²) | Stack is nearly sorted; n is small enough that O(n²) is fast |
| `0.20 – 0.50` (2000–4999) | Medium O(n√n) | Partial disorder benefits from chunk partitioning |
| `≥ 0.50` (≥ 5000) | Complex O(n log n) | High disorder requires the most efficient strategy |

These thresholds match the complexity targets defined in the subject and were validated against the performance benchmarks (100 and 500 random integers).

---

### Contributor Responsibilities

| Author | Responsibilities |
|---|---|
| **mahendri** | Input validation and error handling, argument parsing (flags, overflow detection, duplicates), stack operation primitives (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`), disorder computation, flag parsing (`--simple`, `--medium`, `--complex`, `--adaptive`, `--bench`), strategy selection logic, benchmark output |
| **ainrakot** | All four sorting algorithm implementations (`solver_simple`, `solver_medium`, `solver_complex`), solver orchestration (`solver_main`), checker bonus program (`checker`) |

Both authors contributed to debugging, testing, and review of all parts of the project.

## Resources

- [Sorting Algorithms — Visualgo](https://visualgo.net/en/sorting)
- [Radix Sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Big-O Complexity Cheat Sheet](https://www.bigocheatsheet.com/)
- [push_swap Visualizer](https://push-swap42-visualizer.vercel.app/)

### AI Usage in This Project

- Documentation — README structure, section wording, and complexity argument write-up
- Code review — identifying edge cases in validation logic and flag parsing
- Concept clarification — Big-O analysis of each algorithm in the Push_swap operation model
# push_swap
