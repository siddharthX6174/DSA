int left = 0;
long long window = 0;   // or any data structure (map, set, freq array)
int ans = 0;

for (int right = 0; right < n; right++) {
    // 1️⃣ expand window (include right element)
    window += nums[right];

    // 2️⃣ shrink window while condition breaks
    while (condition_not_valid) {
        window -= nums[left];
        left++;
    }

    // 3️⃣ update answer when condition is valid
    ans = max(ans, right - left + 1);
}
