/**
 * 
 */
package cscie97.asn3.squaredesk.renter;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

/**
 * @author vinodhalaharvi
 *
 */
public final class KnowledgeGraph { 
	private static Map<String, Node> nodeMap; 
	private static Map<String, Predicate> predicateMap; 
	private static Map<String, Triple> tripleMap; 
	private static Map<String, Set<Triple>> queryMapSet; 

	private static KnowledgeGraph kg; 

	/**
	 * Initialize static fields of this class
	 */
	private KnowledgeGraph() {
		nodeMap = new HashMap<String, Node>();
		predicateMap = new HashMap<String, Predicate>();
		tripleMap = new HashMap<String, Triple>();
		queryMapSet = new HashMap<String, Set<Triple>>();
	}	

	/**
	 * Helper function (NOT in the design document) to get the triples
	 * associated with a query line like "Joe ? ?"
	 */
	public static Set<Triple> getTripleSet(Set<Triple> ts, Triple t){ 
		String [] b = t.getIdentifier().split(" "); 
		List<ArrayList<Integer>> c = new ArrayList<ArrayList<Integer>>(); 
		//Get the permutation indices
		c.add(new ArrayList<Integer>(Arrays.asList(0)));
		c.add(new ArrayList<Integer>(Arrays.asList(1)));
		c.add(new ArrayList<Integer>(Arrays.asList(2)));
		c.add(new ArrayList<Integer>(Arrays.asList(0,1)));
		c.add(new ArrayList<Integer>(Arrays.asList(0,2)));
		c.add(new ArrayList<Integer>(Arrays.asList(1,2)));
		c.add(new ArrayList<Integer>(Arrays.asList(0,1,2)));

		//Apply permutation indices on the Triples
		for (ArrayList<Integer> e :c ){
			for (Integer i : e){
				b[i] = "?";
			}
			ts.add(new Triple(new Node(b[0]), new Predicate(b[1]), 
					new Node(b[2])));  
			b = t.getIdentifier().split(" ");
		}
		return ts; 
	}

	public static void addTriple(Triple t) {
		String [] tokens = t.getIdentifier().split(" ");
		Node n = new Node(tokens[0]);
		Predicate p = new Predicate(tokens[1]);
		Node s = new Node(tokens[2]);
		nodeMap.put(tokens[0], n);
		predicateMap.put(tokens[1], p);
		nodeMap.put(tokens[2], s);
		tripleMap.put(t.getIdentifier(), t);
		Set<Triple> ts = new HashSet<Triple>();
		getTripleSet(ts, t);

		// this will add for example
		// Joe has_friend Bill
		if (!queryMapSet.containsKey(t.getIdentifier())){
			//System.out.println("ADDING:" + t.getIdentifier());
			queryMapSet.put(t.getIdentifier(), new HashSet<Triple>());
		}
		queryMapSet.get(t.getIdentifier()).add(t);
		// this will add the combinations of the string
		// Joe has_friend Bill
		// for example 
		// ? has_friend Bill
		// ? ? Bill 
		//etc.
		for(Triple e: ts){  
			if (!queryMapSet.containsKey(e.getIdentifier())){
				//System.out.println("ADDING:" + e.getIdentifier());
				queryMapSet.put(e.getIdentifier(), new HashSet<Triple>());
			}
			queryMapSet.get(e.getIdentifier()).add(t);
		} 
	}


	public static void removeTriple(Triple t) {
		Set<Triple> ts = new HashSet<Triple>();
		getTripleSet(ts, t);
		if (!queryMapSet.containsKey(t.getIdentifier())){
			new TripleNotFoundException("No such Triple found" + t.toString()); 
		}
		queryMapSet.get(t.getIdentifier()).remove(t);
		for(Triple e: ts){  
			if (!queryMapSet.containsKey(e.getIdentifier())){
				new TripleNotFoundException("No such Triple found" + e.toString()); 
			}
			queryMapSet.get(e.getIdentifier()).remove(t);
		}
	}


	/**
	 * imoprtTriples, called by QueryEngine class
	 */
	public static void importTriples(List<Triple> tripleList) {
		/*
		 * Get the tripleList from Importer 
		 * Iterate over each Triple
		 * Prepare the permutations for QueryMapSet
		 * Fill in the QueryMapSet
		 * Fill in nodeMap, predicateMap, tripleMap
		 * */
		for (Triple t: tripleList){
			String [] tokens = t.getIdentifier().split(" ");
			Node n = new Node(tokens[0]);
			Predicate p = new Predicate(tokens[1]);
			Node s = new Node(tokens[2]);
			nodeMap.put(tokens[0], n);
			predicateMap.put(tokens[1], p);
			nodeMap.put(tokens[2], s);
			tripleMap.put(t.getIdentifier(), t);
			Set<Triple> ts = new HashSet<Triple>();
			getTripleSet(ts, t);
			if (!queryMapSet.containsKey(t.getIdentifier())){
				queryMapSet.put(t.getIdentifier(), new HashSet<Triple>());
			}
			queryMapSet.get(t.getIdentifier()).add(t);
			for(Triple e: ts){  
				if (!queryMapSet.containsKey(e.getIdentifier())){
					queryMapSet.put(e.getIdentifier(), new HashSet<Triple>());
				}
				queryMapSet.get(e.getIdentifier()).add(t);
			} 
		}
	}


	/**
	 * execute the query. A Triple set is already formed for this query to get O(1) performance
	 * this methods just's returns that entry from queryMapSet
	 */
	public static Set<Triple> executeQuery(Triple query) {
		if (queryMapSet.containsKey(query.getIdentifier())){ 			
			return  queryMapSet.get(query.getIdentifier());  
		} else { 
			return new HashSet<Triple>(); 
		}
	}

	/**
	 * generate Instance and return to the client
	 */
	public static KnowledgeGraph getInstance() {
		if (kg == null){ 
			kg = new KnowledgeGraph();  
			return kg; 
		} else {
			return kg; 
		}
	}

	/**
	 * Get node using pre calculated nodeMap
	 */
	public static Node getNode(String identifier) {
		if (nodeMap.containsKey(identifier)){ 
			return nodeMap.get(identifier);   
		} else { 
			return null; 
		}
	}


	/**
	 * Get predicate using pre calculated predicateMap 
	 */
	public static Predicate getPredicate(String identifier) {
		if (predicateMap.containsKey(identifier)){ 
			return predicateMap.get(identifier);
		} else {
			return null; 
		}
	}

	/**
	 * Get triple using pre calculated tripleMap
	 */
	public static Triple getTriple(String identifier) {
		return tripleMap.get(identifier); 
	}
}