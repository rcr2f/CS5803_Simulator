
#include "timing_table.h"


Timing_Table::Timing_Table(ostream * out, int num_instr, bool is_CDC6600)
{
	m_num_instr = num_instr;
	outFile = out;
	m_issue = new int[m_num_instr]();
    m_start = new int[m_num_instr]();
	m_result = new int[m_num_instr]();
	m_unit_ready = new int[m_num_instr]();
	fetch = new bool[m_num_instr]();
	m_fetch = new int[m_num_instr]();
	store = new bool[m_num_instr]();
	m_store = new int[m_num_instr]();
	m_is6600 = is_CDC6600;
	
	*outFile << "issue" << ",";
	*outFile <<"start" << ",";
	*outFile << "result" << ",";
	*outFile << "unit ready" << ",";
	*outFile << "fetch" << ",";
	*outFile << "store" << ",";
	*outFile << endl;
}

void Timing_Table::print()
{
	for(int i=0; i<m_num_instr; i++) {
		*outFile << m_issue[i] << ",";
		*outFile << m_start[i] << ",";
		*outFile << m_result[i] << ",";
		*outFile << m_unit_ready[i] << ",";
		if(fetch[i] and not (i==m_num_instr-1)) {
			if(m_is6600)
				*outFile << m_result[i]+5 << ",";
			else
				*outFile << m_result[i]+4 << ",";
			}
		else
			*outFile <<" ;";
		if(i==m_num_instr-1){
			if(m_is6600)
				*outFile << m_result[i]+5 << ",";
			else
				*outFile << m_result[i]+4 << ",";
			}
		*outFile << endl;
	}
		
}
