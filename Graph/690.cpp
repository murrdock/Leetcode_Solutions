class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        Employee* target = nullptr;
        for(int i = 0; i < employees.size(); i++){
            if(employees[i]->id == id){
                target = employees[i];
                break;
            }
        }
        int ans = target->importance;
        vector<int> ve = target->subordinates;
        for(int i = 0; i < ve.size(); i++){
            ans += getImportance(employees, ve[i]);
        }
        return ans;
    }
};
