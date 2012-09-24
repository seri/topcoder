int monthsUntilCrowded(int volume, int males, int females) {
    int lim = 2 * volume, ret = 0, more = males < females ? males : females;
    for (int pop = males + females; pop <= lim; pop += more * (1 << ret)) {
        ++ret;
    }
    return ret;
}
