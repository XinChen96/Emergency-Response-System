/* Build tables for DB */
CREATE TABLE IF NOT EXISTS groups (id integer PRIMARY KEY, groupName text NOT NULL UNIQUE, date text);
CREATE TABLE users (id integer PRIMARY KEY, firstName text NOT NULL, lastName text NOT NULL, username text NOT NULL UNIQUE, role integer NOT NULL);
CREATE TABLE IF NOT EXISTS userGroups (id integer PRIMARY KEY, group_id integer NOT NULL, user_id integer NOT NULL, FOREIGN KEY(group_id) REFERENCES groups(id), FOREIGN KEY(user_id) REFERENCES users(id));
CREATE TABLE simulations (id integer PRIMARY KEY, name text NOT NULL UNIQUE, lat real, lng real, radius real, num_civilians integer, trigger integer);

/* Create civilians */
INSERT INTO users (firstName, lastName, username, role) VALUES("Ben", "Fuller", "fullerb", "Civilian");
INSERT INTO users (firstName, lastName, username, role) VALUES("Joseph", "Teddick", "teddickj", "Civilian");
INSERT INTO users (firstName, lastName, username, role) VALUES("Chen", "Xin", "xinc", "Civilian");
INSERT INTO users (firstName, lastName, username, role) VALUES("Robert", "Jordan", "jordanr", "Civilian");
INSERT INTO users (firstName, lastName, username, role) VALUES("Paul", "Erdos", "erdosp", "Civilian");

/* Create responders */
INSERT INTO users (firstName, lastName, username, role) VALUES("Ben", "Fuller", "benresponder", "First Responder");
INSERT INTO users (firstName, lastName, username, role) VALUES("Joseph", "Teddick", "joeresponder", "First Responder");
INSERT INTO users (firstName, lastName, username, role) VALUES("Chen", "Xin", "chenresponder", "First Responder");
INSERT INTO users (firstName, lastName, username, role) VALUES("Robert", "Jordan", "robertresponder", "First Responder");
INSERT INTO users (firstName, lastName, username, role) VALUES("Paul", "Erdos", "paulresponder", "First Responder");

/* Create groups for responders */
INSERT INTO groups (groupName, date) VALUES("Police Group 1", DATE('now'));
INSERT INTO groups (groupName, date) VALUES("Police Group 2", DATE('now'));
INSERT INTO groups (groupName, date) VALUES("Firemen Group 1", DATE('now'));

/* Add responders to groups */
INSERT INTO userGroups (group_id, user_id) VALUES(0,0); /* Add ben to police group 1 */
INSERT INTO userGroups (group_id, user_id) VALUES(0,2); /* Add ben to firemen group 1 */
INSERT INTO userGroups (group_id, user_id) VALUES(1,1); /* Add Joseph to police group 2 */
INSERT INTO userGroups (group_id, user_id) VALUES(2,2); /* Add chen to firemen group 1 */
INSERT INTO userGroups (group_id, user_id) VALUES(4,1); /* Add paul to police group 1 */
