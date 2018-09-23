
# requirements for credential rotation 

1. distribution mechanism must support test stage, staged rollout, rollback
2. have overlap between old and new : pick new credentials after X time, expire old credentials after Y time
3. provide temp credentials for emergenc
4. old credentials work (even if expired) in case system recovers after long downtime
5. how does App pick up new credentials 

