#include<iostream>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
#include<queue>

void fill_adj_list(std::vector<int> * adj_list, const int & num_interactions) {
    int i = 0;
    int bug1, bug2;

    while(i < num_interactions) {
        scanf("%d%d", &bug1, &bug2);
        // Fill the graph adj list
        adj_list[bug1].push_back(bug2);
        adj_list[bug2].push_back(bug1);
        i++;
    }
}
enum GENDERS {UNKNOWN, MALE, FEMALE};
bool isBipartide(const std::vector<int> * adj_list, const int & num_bugs) {
    int colors[num_bugs + 1];
    for (int i = 1; i <= num_bugs; i++) colors[i] = UNKNOWN;
    // Graph coloring
    // 1. Color first source vertex as male
    // 2. Color all neighbors as female
    // 3. Color all neighbor neighbors male
    // 4. Repeat until all bugs are gendered, or we find homo bugs

    // Pick random source index
    int source = num_bugs;
    std::queue<int> bug_q; // BFS
    colors[source] = MALE;
    bug_q.push(source);
    int num_marked = 1;
    while (!bug_q.empty()) {
        int current = bug_q.front();
        bug_q.pop();
        for (int i = 0; i < adj_list[current].size(); i++) {
            int neighbor = adj_list[current][i];
            if (current == neighbor) return false; // No self loops
            else if (colors[current] == MALE && colors[neighbor] == MALE)
                return false;
            else if (colors[current] == FEMALE && colors[neighbor] == FEMALE)
                return false;
            /* Not in current */
            else if (colors[neighbor] == UNKNOWN) {
                num_marked++;
                colors[neighbor] = colors[current] == MALE ? FEMALE : MALE; // Flip the color
                bug_q.push(neighbor);
            }
        }

    }
    return true;
}

int main() {
    int num_bugs;
    int num_interactions;
    int num_scenarios;
    scanf("%d", &num_scenarios);
    int current_scenario = 1;
    while (current_scenario <= num_scenarios) {
        scanf("%d%d", &num_bugs, &num_interactions);

        std::vector<int> adj_list[num_bugs + 1]; // Make indexed at 1
        // Read the input and fill the array
        fill_adj_list(adj_list, num_interactions);
        printf("Scenario #%d:\n", current_scenario);

        if (isBipartide(adj_list, num_bugs))
            printf("No suspicious bugs found!\n");
        else
            printf("Suspicious bugs found!\n");

        current_scenario++;
    }
    return 0;
}
