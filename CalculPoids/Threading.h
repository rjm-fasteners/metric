#pragma once

class THREADING {
public:
	THREADING();
	~THREADING();
	string getTags();
	string getThread();

private:
	string text;
	string tags;
	string thrdTitle;
	string thrdType;

	void threading();
};