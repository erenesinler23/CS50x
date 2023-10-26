<!--
# PROJECT TTILE: Spotify Data Analyzer by Eren Esinler
#### Video Demo:  https://youtu.be/Xr1jp9qnt5w
#### Description:

Github: https://github.com/erenesinler23

The project that I have created is a web application with the use of Flask, with Python,
HTML, CSS integrated with Spotify OAuth 2.0 API's. This web application simply grants the user
their top 5 tracks, top 5 artists and their profile information in the webpage. Also, the "button" under
the dashboard shows the JSON file of their Spotify Data, so if they want, they can analyze the data on their own.
Lastly, the Spotify logo redirects the user to their Spotify page when clicked. Also, I added my own photo to the
webpage and if the user clicks it, they will be redirected to my page.

Spefically, "app.py" is the main function that runs the program, it is connected with "index.html" in the templates list.
Also, "app.py" runs on the localhost and redirects the user to "index" with "/" and calls back with "/callback" itself. "/playlists"
to playlists and "/dashboard" redirect to the dashboard. Furthermore, in the templates folder, there is a dashboard since there are
only 2 important pages in the application. Index and dashboard. In the static folder, there is a folder named "image" to
store the images that are being used in the webpage. Also, dashboard.css and index.css folders are in static, as well.

Design of the webpages was very important since I wanted a page simple as possible but awesome looking at the same time. So, I spent my
time more in css files rather than html files, because I tried to make html files simple enough. In the designing process, I made a
desicion to make the color theme of the web application same as spotify, to give a good vibe to the users and for aesthetic purposes.

The biggest challenge that I have faced during the development was the use of API's and Localhost. In the start, my main goal was
to make a web application to migrate playlists in different music apps such as Spotify, Apple Music, YouTube music but OAuth 2.0
syntax was very difficult for me so I decided only to do Spotify. The localhost error was very bad, it doesn't allowed me to
redirect the page to myself because the code was not awakening the ports. At the end, I solved the problem partially.

In the future, I want to continue developing this web application to add new services such as playlist migration, and many more...

VERY IMPORTANT CLAIMER:
The uploaded version of the code does not contain a .env file, which stores CLIENT_SECRET and CLIENT_ID; I did not uploaded because
of security concerns. You can create your own .env file and define it to the codes that you can find in your Spotify Developer Account.
Please do not copy the code, implement in your own way. Thank You!

-->



