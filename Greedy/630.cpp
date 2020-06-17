class Solution {
public:
   int scheduleCourse(vector<vector<int>>& courses) {
    int n = courses.size();
  	sort(courses.begin(), courses.end(), [](vector<int> &a, vector<int> &b) {
  		return a[1] < b[1];
  	});
  	int currentTotalTime = 0;
  	priority_queue<int> pq;
  	for(int i=0; i<n; i++) {
  		pq.push(courses[i][0]);
  		currentTotalTime += courses[i][0];
  		if(currentTotalTime > courses[i][1]) {
  			// remove the course with the biggest duration
  			int tp = pq.top();
  			pq.pop();
  			currentTotalTime -= tp;
  		}
  	}
  	return pq.size();
  }
};
