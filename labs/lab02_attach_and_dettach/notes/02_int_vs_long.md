# **`long` vs `int` in C**

| Type   | Typical Size (Linux 64-bit) | Range                                                  | Notes                                          |
| ------ | --------------------------- | ------------------------------------------------------ | ---------------------------------------------- |
| `int`  | 4 bytes (32-bit)            | -2,147,483,648 → 2,147,483,647                         | Standard integer, may overflow with big values |
| `long` | 8 bytes (64-bit on 64-bit)  | -9,223,372,036,854,775,808 → 9,223,372,036,854,775,807 | Bigger range, safer for kernel/system limits   |

**Why use `long` for things like PID or `strtol`:**

* Kernel limits (`pid_max`) may exceed `int` range in modern systems.
* `strtol` **returns `long`**, so using `int` would risk overflow.
* Safer across **32-bit and 64-bit systems**.
* Avoids undefined behavior when parsing numbers from user input or `/proc` files.

**TL;DR:**

* `int` → fine for small numbers.
* `long` → safe, future-proof, matches `strtol` return type, good for system-level numeric parsing.

---