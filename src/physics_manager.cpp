#include "../include/physics_manager.h"

void ColiderManager::addColider(const std::shared_ptr<Colider>& colider) {
    coliders.push_back(colider);
}

void ColiderManager::checkColider() {
    for(size_t i = 0; i < coliders.size(); ++i) {
        for(size_t j = i + 1; j < coliders.size(); ++j) {
            if(coliders[i]->isActive() && coliders[j]->isActive()) {
                if(coliders[i]->getBounds().intersects(coliders[j]->getBounds())) {
                    // Se um dos coliders for um trigger, ative seu flag onTrigger
                    if (coliders[i]->isTrigger || coliders[j]->isTrigger) {
                        if (!coliders[i]->onTrigger) {
                            coliders[i]->onTriggerEnter();
                        }
                        if (!coliders[j]->onTrigger) {
                            coliders[j]->onTriggerEnter();
                        }
                        coliders[i]->onTrigger = true;
                        coliders[j]->onTrigger = true;
                    } else { // Se nenhum dos coliders for um trigger, chame onColider
                        coliders[i]->onColider();
                        coliders[j]->onColider();
                    }
                } else { // Se não houver colisão, desative o flag onTrigger
                    if (coliders[i]->onTrigger) {
                        coliders[i]->onTriggerExit();
                        coliders[i]->onTrigger = false;
                    }
                    if (coliders[j]->onTrigger) {
                        coliders[j]->onTriggerExit();
                        coliders[j]->onTrigger = false;
                    }
                }
            }
        }
    }
}

