
class Solution
{
public:
  vector < int >twoSum (vector < int >&nums, int target)
  {
    unordered_map < int, int >um;
      vector < int >ans;
    int key;
    for (int i = 0; i < nums.size (); i++)
      {
	key = nums[i];
	if (um.count (target - key) == 0)
	  {
	    um[key] = i;
	  }
	else
	  {
	    ans.push_back (i);
	    ans.push_back (um[target - key]);
	    return ans;
	  }
      }
    return ans;
  }
};
