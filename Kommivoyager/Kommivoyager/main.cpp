
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ������� ��� ���������� ���������� ������
int findNearestCity(int currentCity, const vector<bool>& visited, const vector<vector<int>>& distances) {
    int nearestCity = -1;
    int minDistance = numeric_limits<int>::max();

    for (int i = 0; i < visited.size(); ++i) {
        if (!visited[i] && distances[currentCity][i] < minDistance) {
            nearestCity = i;
            minDistance = distances[currentCity][i];
        }
    }

    return nearestCity;
}

// ������� ��� ������� ������ ������������
vector<int> TSP(const vector<vector<int>>& distances) {
    int n = distances.size();
    vector<bool> visited(n, false); // ������ ��� ������������ ���������� �������
    vector<int> path; // ������ ��� �������� ������� ��������� �������

    int currentCity = 0; // �������� � ������� ������
    visited[currentCity] = true;
    path.push_back(currentCity);

    for (int i = 0; i < n - 1; ++i) {
        int nearestCity = findNearestCity(currentCity, visited, distances);
        visited[nearestCity] = true;
        path.push_back(nearestCity);
        currentCity = nearestCity;
    }

    return path;
}

// ������� ��� ���������� ������ ���������� ��������
int calculateTotalDistance(const vector<int>& path, const vector<vector<int>>& distances) {
    int totalDistance = 0;

    for (int i = 0; i < path.size() - 1; ++i) {
        totalDistance += distances[path[i]][path[i + 1]];
    }

    return totalDistance;
}

int main() {
    // �������������� ������� ���������� ����� ��������
    vector<vector<int>> distances = {
        { 0, 2, 9, 10 },
        { 1, 0, 6, 4 },
        { 15, 7, 0, 8 },
        { 6, 3, 12, 0 }
    };

    vector<int> path = TSP(distances); // ������� ����������� �������
    int totalDistance = calculateTotalDistance(path, distances); // ��������� ����� ���������� ��������

    // ������� ����������
    cout << "Optimal marshrut: ";
    for (int i : path) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Total length: " << totalDistance << endl;

    return 0;
}