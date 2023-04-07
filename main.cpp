#include <iostream>
#include <vector>
#include <complex>

typedef std::complex<float> complex;

void initInput(std::vector<complex> *input, std::vector<complex> *output) {
    const int N = 1000;
    for (int n = 0; n < N; n++) {
        input->push_back(complex((float) ((n / 63) % 2), 0.0));
        output->push_back(complex(0.0, 0.0));
    }
}

void initInputSine(std::vector<complex> *input, std::vector<complex> *output) {
    const int N = 1000;
    for (int n = 0; n < N; n++) {
        input->push_back(complex(sin((float) n / 23 * 3.14159265359)
                                 + sin((float) n / 500 * 3.14159265359)
                                 + sin((float) n / 209 * 3.14159265359), 0.0));
        output->push_back(complex(0.0, 0.0));
    }
}

void transform(const std::vector<complex> x, std::vector<complex> *X) {
    const int N = x.size();
    for (int k = 0; k < N; k++) {
        for (int n = 0; n < N; n++) {
            (*X)[k] += x[n] * exp(complex(0.0, -1.0) * complex(2 * (float) k * (float) n / (float) N));
        }
    }
}

int main() {
    std::vector<complex> in;
    std::vector<complex> out;

    initInputSine(&in, &out);
    transform(in, &out);

    for (auto x: out) std::printf("%f\n", std::abs(x));

    return 0;
}