function isNumber(s: string): boolean {
    const p1 = /[-+]?[0-9]*.?[0-9]+[eE]?[0-9]+/g
    const p2 = /[-+]?[0-9]*.?[0-9]+/g
    return p1.test(s) || p2.test(s)
};