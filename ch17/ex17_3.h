#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <memory>
#include <sstream>
#include <fstream>
#include <tuple>


class QueryResult;
class TextQuery;
//using result_tuple = std::tuple<std::string, std::shared_ptr<std::set<TextQuery::line_no>>, std::shared_ptr<std::vector<std::string>>>;

class TextQuery {
	
public:
	//using line_no = std::vector<std::string>::size_type;
	typedef std::vector<std::string>::size_type line_no;
	//error: ����˼�룺����ֱ�Ӷ���һ��tuple������������������������ͣ���������ֲ��Ƿ������͵Ĵ���
	//��std::tuple<std::string, std::set<TextQuery::line_no>, std::vector<std::string>> result��
	// result query1(const std::string &) const����������������
	//fixed�����뷵��һ�����ͣ�����ֱ�Ӱ�std::tuple<std::string, std::set<TextQuery::line_no>, std::vector<std::string>>��
	//������д������ǰ�棬���������ͱ����滻��
	//���ִ��������int����ȣ����Զ���int foo();����ȴ����,int a; a foo();!!!!!!!!
	using result_tuple = std::tuple<std::string, std::shared_ptr<std::set<TextQuery::line_no>>, std::shared_ptr<std::vector<std::string>>>;

	TextQuery(std::ifstream&);
	QueryResult query(const std::string &) const;
	result_tuple query_tuple(const std::string &) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

std::ostream &operator<< (std::ostream &os, TextQuery::result_tuple &);


class QueryResult {
	friend std::ostream &print(std::ostream &, const QueryResult&);
public:
	QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p, std::shared_ptr<std::vector<std::string>> f)
		: sought(s), lines(p), file(f) { }
private:
	std::string sought;
	std::shared_ptr<std::set<TextQuery::line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

std::ostream &print(std::ostream &, const QueryResult &);


