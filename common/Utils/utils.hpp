namespace utils {
double esp = 1e-6;

// Calculate cube root using Newton-Raphon method.
double cbrt(double x, int epsilon = utils::esp);

// Calculate cube root using Binary search.
double cbrt_binary(double x, int epsilon = utils::esp);

double abs(double x);

void swap(int &x, int &y);

int pow(const int &base, const int &exp);
} // namespace utils

double utils::cbrt_binary(double x, int epsilon) {
    double low = 0;
    double high = x;
    double mid;

    while (high - low > epsilon) {
        mid = (low + high) / 2;
        if (mid * mid * mid > x)
            high = mid;
        else
            low = mid;
    }

    return low;
}

double utils::cbrt(double x, int epsilon) {
    if (x == 0)
        return 0;

    double guess = x;

    while (true) {
        double next_guess = (2.0 * guess + x / (guess * guess)) / 3.0;
        if (abs(guess - next_guess) < epsilon)
            break;

        guess = next_guess;
    }

    return guess;
}

double utils::abs(double x) {
    return (x < 0) ? -x : x;
}

void utils::swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int utils::pow(const int &base, const int &exp) {
    int ans = 1;
    for (int i = 0; i < exp; i++)
        ans *= base;
    return ans;
}
