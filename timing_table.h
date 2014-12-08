

#ifndef TIMING_TABLE_H_
#define TIMING_TABLE_H_

#include <fstream>

class Timing_Table {
	public:
		int * m_issue;
		int * m_start;
		int * m_result;
		int * m_unit_ready;
		bool * fetch;
		int * m_fetch;
		bool * store;
		int * m_store;
		bool m_is6600;
		int m_num_instr;
		
		ostream * outFile;
		
		Timing_Table() {}
		
		Timing_Table(ostream * out, int num_instr, bool is_CDC6600);
		
		void print();
		
};

#endif /* TIMING_TABLE_H_ */
		
		
		
