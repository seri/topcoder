int numHoles(int number) {
    static int holes[] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
    int ret = 0;
    while (number > 0) {
        ret += holes[number%10];
        number/=10;
    }
    return ret;
}
