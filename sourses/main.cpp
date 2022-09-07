#include "../includes/cache.h"

int main() {
    unsigned n = 0, cacheSz = 0;

    int tmp = scanf("%u %u", &n, &cacheSz);
    assert(tmp == 2);

    cache_t<int> cache(cacheSz);

    int hits = 0;
    for (unsigned cnt = 0; cnt < n; cnt++) {
        int req = 0;

        tmp = scanf("%d", &req);
        assert(tmp == 1);

        int ver = cache.insert(req);

        if (ver) {
            cache.access(req);
            hits++;
        }
    }
    printf("%d\n", hits);

    return 0;
}