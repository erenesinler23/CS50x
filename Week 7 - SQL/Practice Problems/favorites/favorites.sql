sqlite> SELECT MIN(id) AS id, title
   ...> FROM shows
   ...> GROUP BY title;

UPDATE shows SET title = "........" WHERE title LIKE "......";

+-----+------------------------------------+
| id  |               title                |
+-----+------------------------------------+
| 116 | Adventure Time                     |
| 154 | Anne With An E                     |
| 31  | Archer                             |
| 100 | Arrested Development               |
| 24  | Arrow                              |
| 144 | Atlanta                            |
| 20  | Avatar: The Last Airbender         |
| 110 | B99                                |
| 46  | Band of Brothers                   |
| 102 | Black Mirror                       |
| 140 | Blue Mountain State                |
| 8   | Breaking Bad                       |
| 28  | Brooklyn Nine-Nine                 |
| 21  | Cobra Kai                          |
| 41  | Community                          |
| 54  | Criminal Minds                     |
| 42  | Curb Your Enthusiasm               |
| 81  | Evacuate Earth                     |
| 4   | Family Guy                         |
| 3   | Friday Night Lights                |
| 6   | Friends                            |
| 13  | Game of Thrones                    |
| 78  | Gilmore Girls                      |
| 111 | GoT                                |
| 145 | Good Omens                         |
| 25  | Grace and Frankie                  |
| 97  | Grey's Anatomy                     |
| 43  | Hannah Montana                     |
| 1   | How I Met Your Mother              |
| 151 | Hunter X Hunter                    |
| 142 | Its Always Sunny in Philidelphia   |
| 47  | Jeopardy                           |
| 129 | Last Week Tonight with John Oliver |
| 109 | Law and order                      |
| 69  | Lost                               |
| 60  | Mad Men                            |
| 155 | Money Heist                        |
| 138 | New Amsterdam                      |
| 5   | New Girl                           |
| 64  | Norsemen                           |
| 30  | Parks and Rec                      |
| 59  | Parks and Recreation               |
| 86  | Peaky Blinders                     |
| 79  | Reba                               |
| 66  | Regular Show                       |
| 104 | Saturday Night Live                |
| 55  | Shark Tank                         |
| 22  | Sherlock                           |
| 157 | Silicon Valley                     |
| 77  | Six Flying Dragons                 |
| 62  | South Park                         |
| 56  | Star Trek: The Next Generation     |
| 38  | Stranger Things                    |
| 156 | Succession                         |
| 85  | Supernatural                       |
| 67  | Ted Lasso                          |
| 15  | The 100                            |
| 107 | The Bachelorette                   |
| 146 | The Big Bang Theory                |
| 99  | The Crown                          |
| 35  | The Flash                          |
| 45  | The Good Place                     |
| 26  | The Great British Baking Show      |
| 122 | The Haunting of Hill House         |
| 27  | The Mentalist                      |
| 7   | The Office                         |
| 127 | The Originals                      |
| 73  | The Queen's Gambit                 |
| 33  | The Simpsons                       |
| 2   | The Sopranos                       |
| 14  | The Untamed                        |
| 65  | The West Wing                      |
| 68  | The Wire                           |
| 136 | Top Gear                           |
| 50  | Violet Evergarden                  |
| 113 | WandaVision                        |
| 11  | White Collar                       |
| 119 | Yellowstone                        |
| 95  | You                                |
| 132 | billions                           |
| 121 | criminal minds                     |
+-----+------------------------------------+