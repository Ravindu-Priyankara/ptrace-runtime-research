# **`atoi` Unsafeness & Replacement**

**Problems with `atoi`:**

* **No error detection** → returns 0 for invalid strings (`"abc"`)
* **Overflow/underflow ignored** → undefined behavior for very large numbers
* **No bounds checking** → can’t validate PID or limits safely
* **Always returns `int`** → may not hold large kernel/system values

**Safe replacement:** `strtol`

* Returns `long` → larger range, safer for system limits
* Can detect errors:

  * Invalid characters (`endptr`)
  * Overflow/underflow (`errno`)
* Allows bounds checking → `1 ≤ PID ≤ pid_max`
* Supports **different numeric bases** (decimal, hex, octal)

**Example (safe PID parse):**

```c
#include <errno.h>
#include <stdlib.h>

char *endptr;
errno = 0;
long pid = strtol(input, &endptr, 10); // base 10

if(errno != 0 || *endptr != '\0' || pid < 1 || pid > pid_max) {
    // invalid PID
}
```

---
