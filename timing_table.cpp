
#include "timing_table.h"


Timing_Table::Timing_Table(ostream * out, int num_instr)
{
	m_num_instr = num_instr;
	outFile = out;
	m_issue = new int[m_num_instr]();
    m_start = new int[m_num_instr]();
	m_result = new int[m_num_instr]();
	m_unit_ready = new int[m_num_instr]();
	fetch = new bool[m_num_instr];
	m_fetch = new int[m_num_instr]();
	store = new bool[m_num_instr];
	m_store = new int[m_num_instr]();
	
	*outFile << "issue" << ";";
	*outFile <<"start" << ";";
	*outFile << "result" << ";";
	*outFile << "unit ready" << ";";
	*outFile << "fetch" << ";";
	*outFile << "store" << ";";
	*outFile << endl;
}

void Timing_Table::print()
{
	for(int i=0; i<m_num_instr; i++) {
		*outFile << m_issue[i] << ";";
		*outFile << m_start[i] << ";";
		*outFile << m_result[i] << ";";
		*outFile << m_unit_ready[i] << ";";
		if(fetch[i])
			*outFile << m_fetch[i] << ";";
		else
			*outFile <<" ;";
		if(store[i])
			*outFile << m_store[i] << ";";
		*outFile << endl;
	}
		
}
