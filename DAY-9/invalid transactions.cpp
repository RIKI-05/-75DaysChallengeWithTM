class Solution {
public:
    void from_chars(std::string::const_iterator it, const std::string::const_iterator end, int & value)
    {
        value = 0;
        for (; it != end; ++it)
        {
            value *= 10;
            value += *it - '0';
        }
    }
    struct Transaction
    {
        std::string name;
        int time;
        int amount;
        std::string city;
    };
    Transaction parse(const std::string & transaction)
    {
        Transaction ret_val;
        auto f = find(transaction.begin(), transaction.end(), ',');
        auto s = find(f + 1, transaction.end(), ',');
        auto t = find(s + 1, transaction.end(), ',');
        ret_val.name = string(transaction.begin(), f);
        ret_val.city = string(t+1, transaction.end());
        from_chars(f+1, s, ret_val.time);
        from_chars(s+1, t, ret_val.amount);
        return ret_val;
    }
    vector<string> invalidTransactions(vector<string>& transactions) {
        if (transactions.empty()) return {};

        std::unordered_set<int> invalid;
        struct NameTimeInfo
        {
            std::vector<int> indexes;
            bool several_cities = false;
            string city;
            bool invalid = false;
        };
        // name -> time -> name_time_info
        std::unordered_map<string, std::unordered_map<int, NameTimeInfo>> processed;
        // n
        for (int i = 0; i < transactions.size(); ++i)
        {
            const auto transaction = parse(transactions[i]);
            if (transaction.amount > 1000) invalid.insert(i);
            auto & name_time_info = processed[transaction.name][transaction.time];
            name_time_info.indexes.push_back(i);
            if (name_time_info.city.empty())
            {
                name_time_info.city = transaction.city;
            }
            else if (name_time_info.city != transaction.city)
            {
                name_time_info.several_cities = true;
                name_time_info.invalid = true;
            }
        }

        vector<string> ret_val;
        // n
        for (auto & name_transactions : processed)
        {
            for (auto & name_time_info : name_transactions.second)
            {
                for (int i = name_time_info.first + 1; i <= name_time_info.first + 60; ++i)
                {
                    if (auto next_transaction_info_it = name_transactions.second.find(i); next_transaction_info_it != name_transactions.second.end())
                    {
                        if (name_time_info.second.several_cities ||
                            next_transaction_info_it->second.several_cities ||
                            name_time_info.second.city != next_transaction_info_it->second.city)
                        {
                            name_time_info.second.invalid = true;
                            next_transaction_info_it->second.invalid = true;
                        }
                    }
                }
            }
            for (const auto & name_time_info : name_transactions.second)
            {
                if (name_time_info.second.invalid)
                {
                    for (int idx : name_time_info.second.indexes)
                    {
                        invalid.erase(idx);
                        ret_val.push_back(transactions[idx]);
                    }
                }
            }
        }
        for (int idx : invalid)
        {
            ret_val.push_back(transactions[idx]);
        }
        return ret_val;
    }
};