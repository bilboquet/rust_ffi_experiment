pushd .

# build rust_ffi
cd ../rust_ffi && cargo build --release && popd

# run our ts test
deno run --allow-ffi --unstable typescript/main.ts > result.txt

# diff the result
diff result.txt expected.txt

# if error print it
if [ $? -ne 0 ]; then
    echo "Error: result.txt and expected.txt are not the same"
    exit 1
else
    echo "You're the boss test passed"
    exit 0
fi