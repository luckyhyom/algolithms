function isUpper(str) {
    let count = 0;
    for (const s of str) {
        if (s.charCodeAt(0) >= 65 && s.charCodeAt(0) <= 90) {
            count++
        }
    }

    return count;
}
function isUpper2(str) {
    let count = 0;
    for (const s of str) {
        if (s === s.toUpperCase()) {
            count++
        }
    }

    return count;
}