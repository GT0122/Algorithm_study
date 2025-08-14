#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <io.h>

using namespace std;

int** sobel(int** c, int h, int w) {
	/*int** padding_c = new int* [h + 2];
	int** temp_c = new int* [h + 2];
	int** result_c = new int* [h];
	for(int i = 0; i < h + 2; i++) {
		padding_c[i] = new int[w + 2] { 0, };
		temp_c[i] = new int[w + 2] { 0, };
		if(i > 0 && i < h + 1) {
			for(int j = 1; j < w + 1; j++) {
				padding_c[i][j] = c[i - 1][j - 1];
			}
		}
	}

	int filter[3][3] = { {-1, -2, -1}, {0, 0, 0}, {1, 2, 1} };
	for(int i = 1; i < h + 1; i++) {
		for(int j = 1; j < w + 1; j++) {
			temp_c[i][j] = abs(padding_c[i - 1][j - 1] * filter[0][0] + padding_c[i - 1][j] * filter[0][1] + padding_c[i - 1][j + 1] * filter[0][2] + padding_c[i + 1][j - 1] * filter[2][0] + padding_c[i + 1][j] * filter[2][1] + padding_c[i + 1][j + 1] * filter[2][2]);
		}
	}
	for(int i = 1; i < h + 1; i++) {
		for(int j = 1; j < w + 1; j++) {
			temp_c[i][j] += abs(padding_c[i - 1][j - 1] * filter[0][0] + padding_c[i][j - 1] * filter[0][1] + padding_c[i + 1][j - 1] * filter[0][2] + padding_c[i - 1][j + 1] * filter[2][0] + padding_c[i][j + 1] * filter[2][1] + padding_c[i + 1][j + 1] * filter[2][2]);
			temp_c[i][j] = min(temp_c[i][j], 255);
		}
	}

	for(int i = 0; i < h; i++) {
		result_c[i] = new int[w];
		for(int j = 0; j < w; j++) {
			result_c[i][j] = temp_c[i + 1][j + 1];
		}
	}
	
	return result_c;*/

	int** temp_c = new int* [h];
	for(int i = 0; i < h; i++) {
		temp_c[i] = new int[w] { 0, };
	}

	int filter[3][3] = { {-1, -2, -1}, {0, 0, 0}, {1, 2, 1} };
	for(int i = 1; i < h - 1; i++) {
		for(int j = 1; j < w - 1; j++) {
			temp_c[i][j] = abs(c[i - 1][j - 1] * filter[0][0] + c[i - 1][j] * filter[0][1] + c[i - 1][j + 1] * filter[0][2] + c[i + 1][j - 1] * filter[2][0] + c[i + 1][j] * filter[2][1] + c[i + 1][j + 1] * filter[2][2]);
		}
	}

	for(int i = 1; i < h - 1; i++) {
		for(int j = 1; j < w - 1; j++) {
			temp_c[i][j] += abs(c[i - 1][j - 1] * filter[0][0] + c[i][j - 1] * filter[0][1] + c[i + 1][j - 1] * filter[0][2] + c[i - 1][j + 1] * filter[2][0] + c[i][j + 1] * filter[2][1] + c[i + 1][j + 1] * filter[2][2]);
			temp_c[i][j] = min(temp_c[i][j], 255);
		}
	}

	return temp_c;
}

long double mean_c(int** r, int** g, int** b, int h, int w) {
	long double mean_r = 0, mean_g = 0, mean_b = 0;
	for(int i = 1; i < h - 1; i++) {
		for(int j = 1; j < w - 1; j++) {
			mean_r += (abs(r[i - 1][j] - r[i][j]) + abs(r[i + 1][j] - r[i][j]) + abs(r[i][j - 1] - r[i][j]) + abs(r[i][j + 1] - r[i][j])) / 4;
			mean_g += (abs(g[i - 1][j] - g[i][j]) + abs(g[i + 1][j] - g[i][j]) + abs(g[i][j - 1] - g[i][j]) + abs(g[i][j + 1] - g[i][j])) / 4;
			mean_b += (abs(b[i - 1][j] - b[i][j]) + abs(b[i + 1][j] - b[i][j]) + abs(b[i][j - 1] - b[i][j]) + abs(b[i][j + 1] - b[i][j])) / 4;
		}
	}
	mean_r = mean_r / ((h - 1) * (w - 1));
	mean_g = mean_g / ((h - 1) * (w - 1));
	mean_b = mean_b / ((h - 1) * (w - 1));

	return (mean_r + mean_g + mean_b) / 3;
}

long double white_pro(int** r, int** g, int** b, int h, int w) {
	long double count = 0;
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			if(r[i][j] >= 240 && g[i][j] >= 240 && b[i][j] >= 240) {
				count++;
			}
		}
	}
	return count / (h * w);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*string path = "C:\\Users\\ParkGyeongtae\\source\\repos\\Project1\\8873_images\\";
	string fileformat = "*.in";
	struct _finddata_t fd;
	char folder[] = { '1', '2', '3', '4' };
	cout << "filename" << "\t\t" << "mean_c" << "\t\t" << "mean_c_s" << "\t" << "white_p" << "\t\t\t" << "white_p_s" << '\n';
	for(int i = 1; i < 5; i++) {
		cout << i << '\n';
		intptr_t handle = _findfirst((path + to_string(i) + "\\" + fileformat).c_str(), &fd);
		do {
			cout << fd.name << "\t\t";
			string line;
			ifstream file(path + to_string(i) + "\\" + fd.name);
			if(file.is_open()) {
				int h, w, index;
				getline(file, line);
				h = stoi(line.substr(0, line.find(' ')));
				w = stoi(line.substr(line.find(' ') + 1, line.length() - line.find(' ')));
				int** r = new int* [h];
				int** g = new int* [h];
				int** b = new int* [h];
				for(int i = 0; i < h; i++) {
					r[i] = new int[w];
					getline(file, line);
					for(int j = 0; j < w; j++) {
						index = line.find(' ');
						r[i][j] = stoi(line.substr(0, index));
						line = line.substr(index + 1, line.length() - index);
					}
				}

				for(int i = 0; i < h; i++) {
					g[i] = new int[w];
					getline(file, line);
					for(int j = 0; j < w; j++) {
						index = line.find(' ');
						g[i][j] = stoi(line.substr(0, index));
						line = line.substr(index + 1, line.length() - index);
					}
				}

				for(int i = 0; i < h; i++) {
					b[i] = new int[w];
					getline(file, line);
					for(int j = 0; j < w; j++) {
						index = line.find(' ');
						b[i][j] = stoi(line.substr(0, index));
						line = line.substr(index + 1, line.length() - index);
					}
				}

				int** sobel_r = sobel(r, h, w);
				int** sobel_g = sobel(g, h, w);
				int** sobel_b = sobel(b, h, w);

				long double green = 0;
				for(int i = 0; i < h; i++) {
					for(int j = 0; j < w; j++) {
						green += g[i][j];
					}
				}

				cout << mean_c(r, g, b, h, w) << "\t\t";

				cout << mean_c(sobel_r, sobel_g, sobel_b, h, w) << "\t\t";

				cout << white_pro(r, g, b, h, w) << "\t\t";
				cout << white_pro(sobel_r, sobel_g, sobel_b, h, w) << '\n';

				file.close();
			}
		} while(_findnext(handle, &fd) == 0);

		_findclose(handle);
	}*/
	int h, w;
	cin >> h;
	cin >> w;
	int** r = new int* [h];
	int** g = new int* [h];
	int** b = new int* [h];
	for(int i = 0; i < h; i++) {
		r[i] = new int[w];
		for(int j = 0; j < w; j++) {
			cin >> r[i][j];
		}
	}

	for(int i = 0; i < h; i++) {
		g[i] = new int[w];
		for(int j = 0; j < w; j++) {
			cin >> g[i][j];
		}
	}

	for(int i = 0; i < h; i++) {
		b[i] = new int[w];
		for(int j = 0; j < w; j++) {
			cin >> b[i][j];
		}
	}

	int** sobel_r = sobel(r, h, w);
	int** sobel_g = sobel(g, h, w);
	int** sobel_b = sobel(b, h, w);

	long double m_c = mean_c(sobel_r, sobel_g, sobel_b, h, w);
	long double w_prop = white_pro(sobel_r, sobel_g, sobel_b, h, w);

	if(m_c <= 28 && w_prop >= 0.01) {
		cout << 1;
	}
	else if(m_c >= 28 && w_prop <= 0.1) {
		cout << 2;
	}
	else if(m_c >= 28 && w_prop > 0.1) {
		cout << 3;
	} else {
		cout << 4;
	}

	return 0;
}