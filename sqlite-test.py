import sqlite3

# Connecting to a database
conn = sqlite3.connect("example.db")
cursor = conn.cursor()

# Create table
cursor.execute('''
    CREATE TABLE IF NOT EXISTS users (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        name TEXT NOT NULL,
        email TEXT UNIQUE NOT NULL
    )
''')

# Insert data
cursor.execute('INSERT INTO users (name, email) VALUES (?, ?)',
               ('Alice', 'alice@example.com'))

# Querying data
cursor.execute('SELECT * FROM users')
results = cursor.fetchall()  # Fetch all rows
for row in results:
    print(row)

conn.commit()  # Save changes
conn.close()  # Closing connection
