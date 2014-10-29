/**
 * 
 */
package cscie97.asn3.squaredesk.renter;


import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import cscie97.asn3.squaredesk.renter.Triple;

/**
 * @author vinodhalaharvi
 *
 */
public class Importer {
	/**
	 * 
	 */
	public Importer() {
	}
	
	/**
	 * @param filename complete path of the file containing the input N triples
	 */
	public void ImportTripleFile(String filename) throws ImportExecption{
		File file = new File(filename); 
		KnowledgeGraph kg = KnowledgeGraph.getInstance(); 
		List<Triple> triples = new ArrayList<Triple>(); 
		try {
			FileReader fr = new FileReader(file);
			BufferedReader input = new BufferedReader(fr);
			String line; 
			try {
				while ((line = input.readLine()) != null) {
					if (line.equals(""))
						continue;
					line = line.replace('.', ' '); 
					triples.add(new Triple(line.trim()));
				}
				kg.importTriples(triples); 
				input.close();
			} catch (IOException e) {
				e.printStackTrace();
				throw new ImportExecption();  
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			throw new ImportExecption(); 
		} 
	}
}
