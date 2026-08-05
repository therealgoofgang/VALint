# Clean Build Instructions

The C linkage errors have been fixed in the code. You need to perform a **clean rebuild** to clear cached object files.

## In Visual Studio:

1. Open the solution in Visual Studio
2. Go to **Build** menu → **Clean Solution**
3. Wait for it to finish
4. Go to **Build** menu → **Rebuild Solution** 

## Manual Cleanup (Alternative):

If the above doesn't work, manually delete these directories:
- `C:\Users\Jacob\Desktop\VALint\internal\x64\Debug\`
- `C:\Users\Jacob\Desktop\VALint\internal\x64\Release\`
- `C:\Users\Jacob\Desktop\VALint\x64\`

Then rebuild in Visual Studio.

## What Was Fixed:

The `internal/Hookign/ret_spoofing.h` file had `extern "C"` declarations that weren't properly wrapped in a block with guards. This caused C linkage to "leak" into C++ code, making the compiler try to compile STL templates with C linkage (which is illegal).

The fix wraps the extern "C" declarations like this:

```cpp
#ifdef __cplusplus
extern "C" {
#endif

extern void spoofcall_stub();
extern uintptr_t proxy_call_returns[];
extern size_t proxy_call_returns_size;
extern size_t proxy_call_fakestack_size;
extern uintptr_t* proxy_call_fakestack;

#ifdef __cplusplus
}  // end extern "C"
#endif
```

This ensures the C linkage block is properly closed before any C++ code (including the `initialize_spoofcall` function).

## If Issues Persist:

If you still get C linkage errors after a clean rebuild, please share:
1. The full first error message
2. Screenshot of the Build Output window
3. Confirm you did a Clean + Rebuild (not just Build)
