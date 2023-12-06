#include <iostream>
#include <vector>

double sum_elements_with_odd_indices(const std::vector<double>& arr) {
    double sum = 0;
    for (int i = 1; i < arr.size(); i += 2) {
        sum += arr[i];
    }
    return sum;
}

double sum_elements_between_negatives(const std::vector<double>& arr) {
    int first_neg_index = -1;
    int last_neg_index = -1;

    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] < 0) {
            if (first_neg_index == -1) {
                first_neg_index = i;
            }
            last_neg_index = i;
        }
    }

    if (first_neg_index == -1 || last_neg_index == -1) {
        return 0;
    }

    double sum = 0;
    for (int i = first_neg_index + 1; i < last_neg_index; ++i) {
        sum += arr[i];
    }

    return sum;
}

std::vector<double> compress_array(const std::vector<double>& arr) {
    std::vector<double> compressed_arr;

    for (const double& elem : arr) {
        if (std::abs(elem) > 1) {
            compressed_arr.push_back(elem);
        }
    }

    while (compressed_arr.size() < arr.size()) {
        compressed_arr.push_back(0);
    }

    return compressed_arr;
}

int main() {
    std::vector<double> arr = {1, -2, 3, 4, -5, 6, 7, -8, 9};

    double result1 = sum_elements_with_odd_indices(arr);
    double result2 = sum_elements_between_negatives(arr);
    std::vector<double> result3 = compress_array(arr);

    std::cout << "Suma elementiv z neparnymy nomeramy: " << result1 << std::endl;
    std::cout << "Suma elementiv mizh pershym i ostannim vidʺyemnym: " << result2 << std::endl;
    std::cout << "Stysnutyy masyv: ";
    for (const double& elem : result3) {
        std::cout << elem << " ";
    }

    return 0;
}