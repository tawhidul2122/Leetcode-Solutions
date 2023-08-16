class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& input_nums, int window_size) {
    vector<int> result;
    deque<int> max_queue;

    for (int i = 0; i < input_nums.size(); ++i) {
      while (!max_queue.empty() && max_queue.back() < input_nums[i])
        max_queue.pop_back();
      max_queue.push_back(input_nums[i]);
      if (i >= window_size && input_nums[i - window_size] == max_queue.front())
        max_queue.pop_front();
      if (i >= window_size - 1)
        result.push_back(max_queue.front());
    }

    return result;
  }
};
