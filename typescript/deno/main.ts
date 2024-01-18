// ffi.ts

// Determine library extension based on
// your OS.
let libSuffix = "";
switch (Deno.build.os) {
  case "windows":
    libSuffix = "dll";
    break;
  case "darwin":
    libSuffix = "dylib";
    break;
  default:
    libSuffix = "so";
    break;
}

const libName = `../rust_ffi/target/debug/librust_ffi.${libSuffix}`;
// Open library and define exported symbols
const dylib = Deno.dlopen(
  libName,
  {
    "add": { parameters: ["isize", "isize"], result: "isize" },
  } as const,
);

// import from the implementation in TS that has to be tested
import {operand_35, operand_34} from "../node/src/index.ts";


// Call the symbol `add`
const result = dylib.symbols.add(operand_35(), operand_34()); // 69

console.log(`Result from external addition of 35 and 34: ${result}`);