
# Pycon us 2022 Benjamin Zagorsky

zoneinfo

1. always pass tzinfo to datetime
2. use datetime.utcnow() instead of datetime.now()
3. dont use date.today(); instead use datetime.now(ZoneInfo).date()
4. don't do duration arithmetic outside UTC (dt + delta)
5. use zoneinfo instead of pytc
6. dont replace tzinfo in datetime; instead use astimezone() function
7. convert UTC time to localtime for output
8. convert local time to UTC during input
9. convert ISO 8601 string to UTC - do datetime.fromisoformat().astimezone(utc)
