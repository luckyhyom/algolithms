function changeCases(str) {
    let answer = ''
    for (const s of str) {
        if (s === s.toUpperCase()) {
            answer += s.toLowerCase();
        } else {
            answer += s.toUpperCase();
        }
    }

    return answer;
}